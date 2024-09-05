#ifndef MINETIMER_H
#define MINETIMER_H

#include <QLCDNumber>

class MineTimer : public QLCDNumber
{
public:
    MineTimer(QWidget* parent = nullptr);

    void incrementTime();
    int time() const;

private:

    int seconds;
};


#endif // MINETIMER_H
