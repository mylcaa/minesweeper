#include "minecounter.h"

MineCounter::MineCounter(QWidget* parent)
    : QLCDNumber(parent)
{

    this->setDigitCount(3);
    this->display(0);
    this->setStyleSheet(".QLCDNumber { border: 2px inset gray; background-color: black; color: red; }");
    this->setSegmentStyle(QLCDNumber::Flat);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(QSize(65, 35));
}

void MineCounter::setNumMines(unsigned int mines)
{
    numMines = mines;
    display((int)numMines);
}

void MineCounter::setFlagCount(unsigned int flags)
{
    numFlags = flags;
    display((int)numMines - (int)numFlags);
}
