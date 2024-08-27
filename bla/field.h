#ifndef FIELD_H
#define FIELD_H

#include <QFrame>
#include <QGridLayout>
#include <QLayout>
#include <QSet>
#include <algorithm>
#include <random>
#include "square.h"

class Field : public QFrame
{
    Q_OBJECT

public:
    Field(unsigned int rows, unsigned int cols, unsigned int mines, QWidget *parent = nullptr);


    void init();

    QList<QList<Square*>> field;

public slots:


signals:

    void victory();
    void game_over();
    void flag_count(unsigned int);
    void start_game();
    void cover_field();

private:

    void fillField();
    void placeMines(Square*);
    void defeat();
    void addNeighbours();

    unsigned int numRows;
    unsigned int numCols;
    unsigned int numMines;
    unsigned int numCorrectFlags;
    unsigned int numIncorrectFlags;
    unsigned int numRevealedSquares;


    QGridLayout* layout = new QGridLayout;
    QList<Square*> mined_squares;

};

#endif // FIELD_H
