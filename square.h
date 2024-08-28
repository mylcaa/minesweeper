#ifndef SQUARE_H
#define SQUARE_H

#include <QPushButton>
#include <QStateMachine>
#include <QMouseEvent>
#include <QDebug>

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
    explicit Square(coordinates place, QWidget *parent = nullptr);
    ~Square();

    void mousePressEvent(QMouseEvent *e) override;
    void mouseReleaseEvent(QMouseEvent *e) override;
    void addNeighbour(Square* neighbour);
    void placeMine();

    QList<Square*> neighbours;

    bool isMine;
    static bool firstClick;

    unsigned int adjacentMineCnt;
    unsigned int adjacentFlaggedCnt;

signals:
    void left_click();
    void right_click();

    void game_over();
    void reveal_neighbour();
    void reveal();

    void flagged(bool isMine);
    void unflagged(bool isMine);
    void first_click(Square*);
    void revealed();
    void cover_square();

private:

    void setNumber();
    void setupFSM();

    coordinates place_square;

    QStateMachine fsm;
    QState* UnrevealedState;
    QState* RevealedState;
    QState* FlaggedState;

    QIcon blankIcon = QIcon();
    QIcon revealedIcon = QIcon(QPixmap("/home/koshek/Desktop/bla/pictures/blank.png").scaled(QSize(20, 20)));
    QIcon flagIcon = QIcon(QPixmap("/home/koshek/Desktop/bla/pictures/flag.png").scaled(QSize(20, 20)));
    QIcon mineIcon = QIcon(QPixmap("/home/koshek/Desktop/bla/pictures/mine.png").scaled(QSize(20, 20)));

    const QString unrevealedStyleSheet =
        "Square"
        "{"
        "	border: 1px solid darkgray;"
        "	background: qradialgradient(cx : 0.4, cy : -0.1, fx : 0.4, fy : -0.1, radius : 1.35, stop : 0 #fff, stop: 1 #bbb);"
        "	border - radius: 1px;"
        "}";
    const QString revealedStyleSheet =
        "Square"
        "{"
        "	border: 1px solid lightgray;"
        "}";
    const QString revealedWithNumberStylesheet =
        "Square"
        "{"
        "	color: %1;"
        "	font-weight: bold;"
        "	border: 1px solid lightgray;"
        "}";

};

#endif // SQUARE_H
