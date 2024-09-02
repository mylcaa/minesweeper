#ifndef HW_H
#define HW_H

#include <QObject>
#include <QDebug>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdlib.h>
#include <stdio.h>

class hw: public QObject
{
    Q_OBJECT

public:
    hw(int num_rows, int num_cols);
    void main_loop();

    unsigned int Rows, Cols;

    const char PCF8591 = 0x48; // adresa
    int fd, x_move, y_move;

    unsigned int x_pos = 0;
    unsigned int y_pos = 0;

    const int threshold_left = 50;
    const int threshold_right = 250;
    const int threshold_down = 250;
    const int threshold_up = 50;

    unsigned int right_click = 1;
    unsigned int left_click = 1;

    int **field;


signals:

    void flag(unsigned int pos_x, unsigned int pos_y);
    void unflag(unsigned int pos_x, unsigned int pos_y);
    void reveal(unsigned int pos_x, unsigned int pos_y);

};

#endif // HW_H
