#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include <QTimer>
#include <QFrame>
#include <QThread>
#include "field.h"
#include "minecounter.h"
#include "minetimer.h"
#include "hw.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QThread HwThread;

public:

    int Rows, Cols, Mines;
    hw *Hw;

    MainWindow(int rows, int cols, int mines, QWidget *parent = nullptr);

    ~MainWindow();

public slots:
    void HwFlag(unsigned int x, unsigned int y);

signals:

    void victory();
    void game_over();
    void start();
    void new_game();
    void cover_up();
    void probe_hw();

private:

    void setupFSM();
    void initialize();

    QFrame* mainFrame;

    Field* mineField;
    MineCounter* mineCounter;
    MineTimer* mineTimer;
    QPushButton* newGame;
    QTimer* gameClock;

    QIcon smileIcon = QIcon(QPixmap("/home/raspberry/Desktop/minesweeper/project/pictures/smile_emoji.png"));
    QIcon injuredIcon = QIcon(QPixmap("/home/raspberry/Desktop/minesweeper/project/pictures/injured_emoji.png"));
    QIcon sunglassesIcon = QIcon(QPixmap("/home/raspberry/Desktop/minesweeper/project/pictures/sunglasses_emoji.png"));

    QStateMachine fsm;
    QState* NewGameState;
    QState* GamingState;
    QState* WinnerState;
    QState* LoserState;
};
#endif // MAINWINDOW_H
