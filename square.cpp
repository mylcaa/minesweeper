#include "square.h"

bool Square::firstClick = false;

Square::Square(coordinates place, QWidget *parent)
    :
    isMine(false),
    place_square(place),
    adjacentMineCnt(0),
    adjacentFlaggedCnt(0),
    QPushButton(parent)
{
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(QSize(20, 20));
    setCheckable(true);
    setMouseTracking(true);

    setupFSM();
}

Square::~Square()
{
}

void Square:: addNeighbour(Square* neighbour){
    neighbours += neighbour;

    connect(this, SIGNAL(reveal_neighbour()), neighbour, SIGNAL(reveal()));
}

void Square::placeMine()
{
    isMine = true;
    for (auto neighbour : neighbours)
        ++(neighbour -> adjacentMineCnt);
}

void Square::setupFSM(){

    QState* UnrevealedState = new QState();
    QState* RevealedState = new QState();
    QState* FlaggedState = new QState();

    UnrevealedState -> addTransition(this, &Square::left_click, RevealedState);
    UnrevealedState -> addTransition(this, &Square::reveal, RevealedState);
    UnrevealedState -> addTransition(this, &Square::right_click, FlaggedState);

    FlaggedState -> addTransition(this, &Square::right_click, UnrevealedState);
    FlaggedState -> addTransition(this, &Square::cover_square, UnrevealedState);

    RevealedState -> addTransition(this, &Square::cover_square, UnrevealedState);


    connect(UnrevealedState, &QState::entered, [this]()
            {
                //qDebug() << "entered unrevealed state";
                this->setIcon(blankIcon);
                this->setStyleSheet(unrevealedStyleSheet);

            });

    connect(FlaggedState, &QState::entered, [this]()
            {
                //qDebug() << "entered flagged state";
                this->setIcon(flagIcon);
                this->setStyleSheet(unrevealedStyleSheet);

                for(auto neighbour: neighbours){
                    ++(neighbour -> adjacentFlaggedCnt);
                }

                flagged(isMine);

            });

    connect(FlaggedState, &QState::exited, [this]()
            {
                //qDebug() << "exited flagged state";
                this->setIcon(blankIcon);
                this->setStyleSheet(unrevealedStyleSheet);

                for(auto neighbour: neighbours){
                    --(neighbour -> adjacentFlaggedCnt);
                }

                unflagged(isMine);

            });

    connect(RevealedState, &QState::entered, [this]()
            {
                //qDebug() << "entered UNREVEALED";
                this->setIcon(blankIcon);

                if(isMine){
                    game_over();

                    //qDebug() << "clicked on a mine in SQUARE";

                    this->setIcon(mineIcon);

                }else if(adjacentMineCnt){
                    setNumber();

                    //qDebug() << "clicked on a NUMBER in SQUARE";

                    revealed();

                }else{
                    //qDebug() << "entered revealed state with NO MINE in SQUARE";
                    this->setStyleSheet(revealedStyleSheet);
                    reveal_neighbour();

                    revealed();
                }
            });

    /*connect(RevealedState, &QState::exited, [this]()
            {
                //qDebug() << "exited flagged state";
                this->setIcon(blankIcon);
                this->setStyleSheet(unrevealedStyleSheet);

            });*/

    fsm.addState(UnrevealedState);
    fsm.addState(RevealedState);
    fsm.addState(FlaggedState);

    fsm.setInitialState(UnrevealedState);
    fsm.start();
}

void Square::mousePressEvent(QMouseEvent *e)
{
    if(!firstClick){
        firstClick = true;
        first_click(this);
    }
    QPushButton::mousePressEvent(e);
}

void Square::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        emit left_click();
    }
    else if (e->button() == Qt::RightButton){
        emit right_click();
    }
    QPushButton::mouseReleaseEvent(e);
}


void Square::setNumber()
{
    QString color;
    switch (adjacentMineCnt)
    {
    case 1:
        color = "blue";
        break;
    case 2:
        color = "green";
        break;
    case 3:
        color = "red";
        break;
    case 4:
        color = "midnightblue";
        break;
    case 5:
        color = "maroon";
        break;
    case 6:
        color = "darkcyan";
        break;
    case 7:
        color = "black";
        break;
    case 8:
        color = "grey";
        break;
    default:
        break;
    }

    this->setStyleSheet(revealedWithNumberStylesheet.arg(color));
    this->setText(QString::number(adjacentMineCnt));
}
