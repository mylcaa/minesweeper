#include "minetimer.h"

MineTimer::MineTimer(QWidget* parent /*= nullptr*/)
    : QLCDNumber(parent)
    , seconds(0)
{
    this->setDigitCount(4);
    this->display(0);
    this->setStyleSheet(".QLCDNumber { border: 2px inset gray; background-color: black; color: red; }");
    this->setSegmentStyle(QLCDNumber::Flat);
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    this->setFixedSize(QSize(65, 35));
}

void MineTimer::incrementTime()
{
    display(++seconds);
}

int MineTimer::time() const
{
    return seconds;
}
