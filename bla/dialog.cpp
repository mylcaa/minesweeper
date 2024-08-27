#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent),
    mainFrame(nullptr),
      ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(this, &Dialog::game_over, this, [this]()
            {
                newGame->setIcon(QIcon(injuredIcon));
            });
    connect(this, &Dialog::victory, this, [this]()
            {
                newGame->setIcon(QIcon(sunglassesIcon));
            });

    //this->layout()->setSizeConstraint(QLayout::SetFixedSize);
    //initialize();

    qDebug() << "init game in constructor: " << init_game;
    setupFSM();

    init();
    adjustSize();

}

void Dialog::init(){

    qDebug() << "init game in init: " << init_game;

    mainFrame = new QFrame(this);
    auto mainFrameLayout = new QVBoxLayout;
    auto infoLayout = new QHBoxLayout;

    mineField = new Field(Rows, Cols, Mines, mainFrame);
    mineCounter = new MineCounter(mainFrame);
    mineTimer = new MineTimer(mainFrame);
    newGame = new QPushButton(mainFrame);
    gameClock = new QTimer(this);

    mineCounter->setNumMines(Mines);

    //connect(this, &Dialog::unreveal, mineField, &Field::cover_field);

    connect(mineField, &Field::start_game, this, &Dialog::start);
    connect(mineField, &Field::flag_count, mineCounter, &MineCounter::setFlagCount);
    connect(mineField, &Field::victory, this, &Dialog::victory);
    connect(mineField, &Field::game_over, this, &Dialog::game_over);

    newGame->setMinimumSize(35, 35);
    newGame->setIconSize(QSize(30, 30));
    newGame->setIcon(smileIcon);
    connect(newGame, &QPushButton::clicked, this, &Dialog::new_game);

    gameClock->setInterval(1000);
    connect(gameClock, &QTimer::timeout, mineTimer, &MineTimer::incrementTime);

    infoLayout->addWidget(mineCounter);
    infoLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding));
    infoLayout->addWidget(newGame);
    infoLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding));
    infoLayout->addWidget(mineTimer);


    mainFrameLayout->addLayout(infoLayout);
    mainFrameLayout->addWidget(mineField);

    mainFrame->setLayout(mainFrameLayout);

    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    //this->setCentralWidget(newMainFrame);

}


void Dialog::initialize(){

    QFrame* newMainFrame = new QFrame(this);
    auto mainFrameLayout = new QVBoxLayout;
    auto infoLayout = new QHBoxLayout;

    mineField = new Field(Rows, Cols, Mines, newMainFrame);
    mineCounter = new MineCounter(newMainFrame);
    mineTimer = new MineTimer(newMainFrame);
    newGame = new QPushButton(newMainFrame);
    gameClock = new QTimer(this);

    mineCounter->setNumMines(Mines);

    //connect(this, &Dialog::unreveal, mineField, &Field::cover_field);

    connect(mineField, &Field::start_game, this, &Dialog::start);
    connect(mineField, &Field::flag_count, mineCounter, &MineCounter::setFlagCount);
    connect(mineField, &Field::victory, this, &Dialog::victory);
    connect(mineField, &Field::game_over, this, &Dialog::game_over);

    newGame->setMinimumSize(35, 35);
    newGame->setIconSize(QSize(30, 30));
    newGame->setIcon(smileIcon);
    connect(newGame, &QPushButton::clicked, this, &Dialog::new_game);

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
    //this->setCentralWidget(newMainFrame);

    std::swap(mainFrame, newMainFrame);
    mainFrame -> deleteLater();

}

void Dialog::setupFSM(){

    QState* NewGameState = new QState();
    QState* GamingState = new QState();
    QState* WinnerState = new QState();
    QState* LoserState = new QState();

    NewGameState -> addTransition(this, &Dialog::start, GamingState);

    GamingState -> addTransition(this, &Dialog::victory, WinnerState);
    GamingState -> addTransition(this, &Dialog::game_over, LoserState);
    GamingState -> addTransition(this, &Dialog::new_game, NewGameState);

    WinnerState -> addTransition(this, &Dialog::new_game, NewGameState);
    LoserState -> addTransition(this, &Dialog::new_game, NewGameState);

    connect(NewGameState, &QState::entered, [this]()
            {
                qDebug() << "NEW GAME";
                qDebug() << init_game;

                if(init_game){
                    qDebug() << "init";
                    qDebug() << init_game;
                    initialize();
                }

            });

    connect(GamingState, &QState::entered, [this]()
            {
                qDebug() << "GAMING";
                init_game = true;
                gameClock->start();
            });

    connect(WinnerState, &QState::entered, [this]()
            {
                qDebug() << "WIN";
                gameClock->stop();
            });

    connect(LoserState, &QState::entered, [this]()
            {
                qDebug() << "LOSEEEEEE";
                gameClock->stop();
            });

    fsm.addState(NewGameState);
    fsm.addState(GamingState);
    fsm.addState(WinnerState);
    fsm.addState(LoserState);

    fsm.setInitialState(NewGameState);
    fsm.start();
}

Dialog::~Dialog()
{
    delete ui;
}
