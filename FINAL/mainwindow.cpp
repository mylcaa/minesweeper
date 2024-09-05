#include "mainwindow.h"

MainWindow::MainWindow(int rows, int cols, int mines, QWidget *parent)
    : QMainWindow(parent),
    Rows(rows),
    Cols(cols),
    Mines(mines),
    mainFrame(nullptr)
{

    connect(this, &MainWindow::game_over, this, [this]()
            {
                newGame->setIcon(QIcon(injuredIcon));
            });
    connect(this, &MainWindow::victory, this, [this]()
            {
                newGame->setIcon(QIcon(sunglassesIcon));
            });

    this->setWindowTitle("MINE");


    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::Hw);
    timer -> start(200);



    wiringPiSetup();
    fd = wiringPiI2CSetup(PCF8591);

    pinMode(21, INPUT);
    pinMode(22, INPUT);

    pinMode(25, OUTPUT);
    pinMode(26, OUTPUT);
    pinMode(27, OUTPUT);
    pinMode(28, OUTPUT);

    setupFSM();
    adjustSize();


}

MainWindow::~MainWindow() {

    delete mainFrame;

}

void MainWindow:: Hw(){

    wiringPiI2CReadReg8(fd, PCF8591 + 0) ; // dummy
    x_move = wiringPiI2CReadReg8(fd, PCF8591 + 0);
    qDebug() << "x move" << x_move;

    if(x_move < threshold_left){
        qDebug() << "left" << x_move;

     if(x_pos > 0){
            x_pos--;
        }else{
            x_pos = Cols-1;
        }

    }else if(x_move > threshold_right){
     qDebug() << "right" << x_move;

        if(x_pos < Cols-1){
            x_pos++;
        }else{
            x_pos = 0;
        }
    }

    wiringPiI2CReadReg8(fd, PCF8591 + 1) ; // dummy
    y_move = wiringPiI2CReadReg8(fd, PCF8591 + 1);
    qDebug() << "y move" << y_move;


     if(y_move > threshold_down || y_move == -1){
        qDebug() << "down" << y_move;

        if(y_pos < Rows-1){
            y_pos++;
        }else{
            y_pos = 0;
        }
    }else if(y_move < threshold_up){
        qDebug() << "up" << y_move;

        if(y_pos > 0){
            y_pos--;
        }else{
            y_pos = Rows-1;
        }
    }

    delay(500);

    //PRICA ZA TASTERE:

        right_click = digitalRead(21);
        //printf("right click = %d \n\n" , right_click);

        if(!right_click){
        //printf("right click = %d \n\n" , right_click);
        qDebug() << "right click";
        right_click = 1;

            if(!(mineField -> hw_field[y_pos][x_pos])){
                flag(y_pos, x_pos);
                qDebug() << "flag " << x_pos << y_pos;
            }else if(mineField -> hw_field[y_pos][x_pos]){
                qDebug() << "unflag " << x_pos << y_pos;
                unflag(y_pos, x_pos);
            }

        }


        left_click = digitalRead(22);
        //printf("left click = %d \n\n" , left_click);


        if(!left_click){
        qDebug() << "left click";

            left_click = 1;

            if(!Square::firstClick){
                Square::firstClick = true;
            }

            if(!(mineField -> hw_field[y_pos][x_pos])){
                areveal(y_pos, x_pos);
                qDebug() << "reveal " << x_pos << y_pos;
            }
        }

        delay(500);

}

void MainWindow::initialize(){

    QFrame* newMainFrame = new QFrame(this);
    auto mainFrameLayout = new QVBoxLayout;
    auto infoLayout = new QHBoxLayout;

    mineField = new Field(Rows, Cols, Mines, newMainFrame);
    mineCounter = new MineCounter(newMainFrame);
    mineTimer = new MineTimer(newMainFrame);
    newGame = new QPushButton(newMainFrame);
    gameClock = new QTimer(this);

    mineCounter->setNumMines(Mines);

    connect(mineField, &Field::start_game, this, &MainWindow::start);
    connect(mineField, &Field::flag_count, mineCounter, &MineCounter::setFlagCount);
    connect(mineField, &Field::victory, this, &MainWindow::victory);
    connect(mineField, &Field::game_over, this, &MainWindow::game_over);

    connect(this, SIGNAL(flag(unsigned int, unsigned int)), mineField, SLOT(hw_flag(unsigned int, unsigned int)));
    connect(this, SIGNAL(areveal(unsigned int, unsigned int)), mineField, SLOT(hw_reveal(unsigned int, unsigned int)));
    connect(this, SIGNAL(unflag(unsigned int, unsigned int)), mineField, SLOT(hw_unflag(unsigned int, unsigned int)));

    newGame->setMinimumSize(35, 35);
    newGame->setIconSize(QSize(30, 30));
    newGame->setIcon(smileIcon);
    connect(newGame, &QPushButton::clicked, this, &MainWindow::new_game);

    gameClock->setInterval(1000);
    connect(gameClock, &QTimer::timeout, mineTimer, &MineTimer::incrementTime);

    infoLayout->addWidget(mineCounter);
    infoLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding));
    infoLayout->addWidget(newGame);
    infoLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding));
    infoLayout->addWidget(mineTimer);


    mainFrameLayout->addLayout(infoLayout);
    mainFrameLayout->addWidget(mineField);

    newMainFrame->setLayout(mainFrameLayout);

    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    this->setCentralWidget(newMainFrame);

    std::swap(mainFrame, newMainFrame);
    delete newMainFrame;

}

void MainWindow::setupFSM(){

    QState* NewGameState = new QState();
    QState* GamingState = new QState();
    QState* WinnerState = new QState();
    QState* LoserState = new QState();

    NewGameState -> addTransition(this, &MainWindow::start, GamingState);

    GamingState -> addTransition(this, &MainWindow::victory, WinnerState);
    GamingState -> addTransition(this, &MainWindow::game_over, LoserState);
    GamingState -> addTransition(this, &MainWindow::new_game, NewGameState);

    WinnerState -> addTransition(this, &MainWindow::new_game, NewGameState);
    LoserState -> addTransition(this, &MainWindow::new_game, NewGameState);

    connect(NewGameState, &QState::entered, [this]()
            {

                initialize();
                Square::firstClick = false;
                qDebug() << "new game";


            });

    connect(GamingState, &QState::entered, [this]()
            {
                gameClock->start();
                qDebug() << "gaming";



            });

    connect(WinnerState, &QState::entered, [this]()
            {
                gameClock->stop();

                for(int i=0; i<4; ++i){
                    digitalWrite(LED[0], mask[i]);
                    digitalWrite(LED[1], !mask[i+2]);
                    digitalWrite(LED[2], !mask[i]);
                    digitalWrite(LED[3], mask[i+2]);

                    delay(200);
                }

                for(int i=0; i<4; ++i){
                    digitalWrite(LED[i], 0);
                }



            });

    connect(LoserState, &QState::entered, [this]()
            {
                gameClock->stop();

                for(int i=0; i<4; ++i){
                    digitalWrite(LED[0], !mask[i]);
                    digitalWrite(LED[1], mask[i+2]);
                    digitalWrite(LED[2], mask[i]);
                    digitalWrite(LED[3], !mask[i+2]);

                    delay(200);
                }

                for(int i=0; i<4; ++i){
                    digitalWrite(LED[i], 0);
                }
            });

    fsm.addState(NewGameState);
    fsm.addState(GamingState);
    fsm.addState(WinnerState);
    fsm.addState(LoserState);

    fsm.setInitialState(NewGameState);
    fsm.start();
}

void MainWindow::HwFlag(unsigned int x, unsigned int y){

    qDebug() << "flag: " << x << " " << y;
}



