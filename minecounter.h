#ifndef MINECOUNTER_H
#define MINECOUNTER_H

#include <QLCDNumber>

class MineCounter : public QLCDNumber
{
    Q_OBJECT

public:
    MineCounter(QWidget* parent = nullptr);

    void setNumMines(unsigned int mines);
    void setFlagCount(unsigned int flags);

private:

    unsigned int numMines;
    unsigned int numFlags;
};


#endif // MINECOUNTER_H
