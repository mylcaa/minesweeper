#include "square.h"
#include "ui_square.h"

Square::Square(coordinates place, QPushButton *parent)
    : place_square(place),
      isMine(false),
      adjacentMineCnt(0),
      adjacentFlaggedCnt(0),
      QPushButton(parent)
{
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setCheckable(true);
    setMouseTracking(true);

    setupFSM();
}

Square::~Square()
{
    delete UnrevealedState;
    delete FlaggedState;
    delete RevealedState;
}

void Square:: addNeighbour(Square* neighbour){
    neighbours += neighbour;

    connect(this, reveal_neighbour(), neighbour, reveal());

}

void Square::setupFSM(){

    QState* UnrevealedState = new QState();
    QState* RevealedState = new QState();
    QState* FlaggedState = new QState();

    UnrevealedState -> addTransition(this, &Square::leftClick(), RevealedState);
    UnrevealedState -> addTransition(this, &Square::reveal(), RevealedState);

    UnrevealedState -> addTransition(this, &Square::rightClick(), FlaggedState);

    FlaggedState -> addTransition(this, &Square::rightClick(), UnrevealedState);

    connect(UnrevealedState, &QState::entered, [this]()
        {
            this->setIcon(blankIcon);
            this->setStyleSheet(unrevealedStyleSheet);

        });

    connect(FlaggedState, &QState::entered, [this]()
        {
            this->setIcon(flagIcon);
            this->setStyleSheet(unrevealedStyleSheet);

            for(auto neighbour: neighbours){
                neighbour -> ++adjacentMineCnt;
            }

        });

    connect(FlaggedState, &QState::exited, [this]()
            {
                this->setIcon(blankIcon);
                this->setStyleSheet(unrevealedStyleSheet);

                for(auto neighbour: neighbours){
                    neighbour -> --adjacentMineCnt;
                }

            });

    connect(RevealedState, &QState::entered, [this]()
            {

                if(isMine){
                    emit game_over();
                    this->setStyleSheet(unrevealedStyleSheet);
                    this->setIcon(mineIcon);

                }else if(adjacentMineCnt){
                    setNumber();

                }else{
                    this->setStyleSheet(unrevealedStyleSheet);
                    reveal_neighbour();

                }
            });

    fsm.addState(unrevealedState);
    fsm.addState(revealedState);
    fsm.addState(flaggedState);

    fsm.setInitialState(unrevealedState);
    fsm.start();
}

void Square::mousePressEvent(QMouseEvent *e)
{
    QPushButton::mousePressEvent(e);
}

void Square::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        qDebug() << "Left";
        emit leftClick();
    }
    else if (e->button() == Qt::RightButton) {

        qDebug() << "Right";
        emit rightClick();

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

    this -> QPushButton::setStyleSheet(revealedWithNumberStylesheet.arg(color));
    this -> QPushButton::setText(QString::number(adjacentMineCnt));
}
