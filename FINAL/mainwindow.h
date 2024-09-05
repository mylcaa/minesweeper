#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include <QTimer>
#include <QFrame>
#include <wiringPiI2C.h>
#include <wiringPi.h>
#include "field.h"
#include "minecounter.h"
#include "minetimer.h"
#include "hw.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    int Rows, Cols, Mines;
    char LED[4] = {25, 26, 27, 28};
    char mask[6] = {1, 0, 0, 0, 1, 0};

    const char PCF8591 = 0x48; // adresa
    int fd, x_move, y_move;

    unsigned int x_pos = 0;
    unsigned int y_pos = 0;

    const int threshold_left = 50;
    const int threshold_right = 210;
    const int threshold_down = 240;
    const int threshold_up = 50;

    unsigned int right_click = 1;
    unsigned int left_click = 1;

    MainWindow(int rows, int cols, int mines, QWidget *parent = nullptr);
    void Hw();

    ~MainWindow();

public slots:
    void HwFlag(unsigned int x, unsigned int y);

signals:

    void victory();
    void game_over();
    void start();
    void new_game();
    void cover_up();

    void flag(unsigned int x, unsigned int y);
    void unflag(unsigned int x, unsigned int y);
    void areveal(unsigned int x, unsigned int y);

private:

    void setupFSM();
    void initialize();

    QFrame* mainFrame;

    Field* mineField;
    MineCounter* mineCounter;
    MineTimer* mineTimer;
    QPushButton* newGame;
    QTimer* gameClock;

    QTimer* hwClock;

    QIcon smileIcon = QIcon(QPixmap("/home/raspberry/Desktop/minesweeper/minesweeper/bla/pictures/smile_emoji.png"));
    QIcon injuredIcon = QIcon(QPixmap("/home/raspberry/Desktop/minesweeper/minesweeper/bla/pictures/injured_emoji.png"));
    QIcon sunglassesIcon = QIcon(QPixmap("/home/raspberry/Desktop/minesweeper/minesweeper/bla/pictures/sunglasses_emoji.png"));

    QStateMachine fsm;
    QState* NewGameState;
    QState* GamingState;
    QState* WinnerState;
    QState* LoserState;
};
#endif // MAINWINDOW_H
