#ifndef SQUARE_H
#define SQUARE_H

#include <QPushButton>
#include <QStateMachine>

struct coordinates
{
    unsigned int x;
    unsigned int y;
};

const QString unrevealedStyleSheet =
    "Tile"
    "{"
    "	border: 1px solid darkgray;"
    "	background: qradialgradient(cx : 0.4, cy : -0.1, fx : 0.4, fy : -0.1, radius : 1.35, stop : 0 #fff, stop: 1 #bbb);"
    "	border - radius: 1px;"
    "}";
const QString revealedStyleSheet =
    "Tile"
    "{"
    "	border: 1px solid lightgray;"
    "}";
const QString revealedWithNumberStylesheet =
    "Tile"
    "{"
    "	color: %1;"
    "	font-weight: bold;"
    "	border: 1px solid lightgray;"
    "}";



namespace Ui {
class Square;
}

class Square : public QPushButton
{
    Q_OBJECT

public:
    explicit Square(coordinates place, QPushButton *parent = nullptr);
    ~Square();

    QStateMachine square_state;

private:

    void setNumber();
    void setupFSM();

    coordinates place_square;

    unsigned int adjacentMineCnt;
    unsigned int adjacentFlaggedCnt;

    QList<Square*> neighbors;
    static bool firstClick;
    Qt::MouseButtons buttons;

};

#endif // SQUARE_H
