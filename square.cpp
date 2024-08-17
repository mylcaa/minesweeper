#include "square.h"
#include "ui_square.h"

Square::Square(coordinates place, QPushButton *parent)
    : place_square(place),
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

void Square::setupFSM(){

    QState* UnrevealedState = new QState();
    QState* RevealedState = new QState();
    QState* FLaggedState = new QState();



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
