#ifndef SQUARE_H
#define SQUARE_H

#include <QPushButton>
#include <QStateMachine>

struct coordinates
{
    unsigned int x;
    unsigned int y;
};



namespace Ui {
class Square;
}

class Square : public QPushButton
{
    Q_OBJECT

public:
    explicit Square(coordinates place, QPushButton *parent = nullptr);
    ~Square();

    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;

    QStateMachine square_state;
    QList<Square*> neighbours;

signals:
    void leftClick();
    void rightClick();

    void game_over();
    void reveal_neighbour();
    void reveal();

private:

    void setNumber();
    void setupFSM();

    coordinates place_square;

    bool isMine;
    unsigned int adjacentMineCnt;
    unsigned int adjacentFlaggedCnt;

    QStateMachine fsm;
    QState* unrevealedState;
    QState* revealedState;
    QState* flaggedState;

    const QString unrevealedStyleSheet;
    const QString revealedStyleSheet;
    const QString unrevealedWithNUmberStyleSheet;

    QIcon blankIcon = QIcon();
    QIcon flagIcon = QIcon(QPixmap(":/flag").scaled(QSize(20, 20)));
    QIcon mineIcon = QIcon(QPixmap(":/mine").scaled(QSize(20, 20)));

};

const QString Square::unrevealedStyleSheet =
    "Tile"
    "{"
    "	border: 1px solid darkgray;"
    "	background: qradialgradient(cx : 0.4, cy : -0.1, fx : 0.4, fy : -0.1, radius : 1.35, stop : 0 #fff, stop: 1 #bbb);"
    "	border - radius: 1px;"
    "}";
const QString Square::revealedStyleSheet =
    "Tile"
    "{"
    "	border: 1px solid lightgray;"
    "}";
const QString Square::revealedWithNumberStylesheet =
    "Tile"
    "{"
    "	color: %1;"
    "	font-weight: bold;"
    "	border: 1px solid lightgray;"
    "}";

#endif // SQUARE_H
