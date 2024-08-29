#include "mainwindow.h"

MainWindow::MainWindow(int rows, int cols, int mines, QWidget *parent)
    : QMainWindow(parent),
    Rows(rows),
    Cols(cols),
    Mines(mines)
{

    connect(this, &MainWindow::game_over, this, [this]()
            {
                newGame->setIcon(QIcon(injuredIcon));
            });
    connect(this, &MainWindow::victory, this, [this]()
            {
                newGame->setIcon(QIcon(sunglassesIcon));
            });

    setupFSM();
}

MainWindow::~MainWindow() {

    delete mainFrame;
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

            });

    connect(GamingState, &QState::entered, [this]()
            {
                gameClock->start();
            });

    connect(WinnerState, &QState::entered, [this]()
            {
                gameClock->stop();
            });

    connect(LoserState, &QState::entered, [this]()
            {
                gameClock->stop();
            });

    fsm.addState(NewGameState);
    fsm.addState(GamingState);
    fsm.addState(WinnerState);
    fsm.addState(LoserState);

    fsm.setInitialState(NewGameState);
    fsm.start();
}



