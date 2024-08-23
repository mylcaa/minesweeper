#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent),
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

    setupFSM();
    initialize();
    adjustSize();

}

void Dialog::initialize(){

    QFrame* newMainFrame = new QFrame(this);
    auto mainFrameLayout = new QVBoxLayout;
    auto infoLayout = new QHBoxLayout;

    MineField = new Field(Rows, Cols, Mines, newMainFrame);
    mineCounter = new MineCounter(newMainFrame);
    mineTimer = new MineTimer(newMainFrame);
    newGame = new QPushButton(newMainFrame);
    gameClock = new QTimer(this);

    mineCounter->setNumMines(Mines);

    connect(MineField, &Field::start_game, this, &Dialog::start, Qt::UniqueConnection);
    connect(MineField, &Field::flag_count, mineCounter, &MineCounter::setFlagCount, Qt::UniqueConnection);
    connect(MineField, &Field::victory, this, &Dialog::victory, Qt::UniqueConnection);
    connect(MineField, &Field::game_over, this, &Dialog::game_over, Qt::UniqueConnection);


    newGame->setMinimumSize(35, 35);
    newGame->setIconSize(QSize(30, 30));
    newGame->setIcon(smileIcon);
    connect(newGame, &QPushButton::clicked, this, &Dialog::new_game, Qt::UniqueConnection);

    gameClock->setInterval(1000);
    connect(gameClock, &QTimer::timeout, mineTimer, &MineTimer::incrementTime, Qt::UniqueConnection);

    infoLayout->addWidget(mineCounter);
    infoLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding));
    infoLayout->addWidget(newGame);
    infoLayout->addSpacerItem(new QSpacerItem(0, 0, QSizePolicy::MinimumExpanding));
    infoLayout->addWidget(mineTimer);


    mainFrameLayout->addLayout(infoLayout);
    mainFrameLayout->addWidget(MineField);

    newMainFrame->setLayout(mainFrameLayout);

    this->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
    //this->setCentralWidget(newMainFrame);

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
                initialize();
            });

    connect(GamingState, &QState::entered, [this]()
            {
                qDebug() << "GAMING";
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
