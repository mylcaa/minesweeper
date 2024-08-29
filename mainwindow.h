#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPointer>
#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include <QTimer>
#include <QFrame>
#include "field.h"
#include "minecounter.h"
#include "minetimer.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    int Rows, Cols, Mines;

    MainWindow(int rows, int cols, int mines, QWidget *parent = nullptr);
    ~MainWindow();


signals:

    void victory();
    void game_over();
    void start();
    void new_game();
    void cover_up();

private:

    void setupFSM();
    void initialize();

    QFrame* mainFrame;

    Field* mineField;
    MineCounter* mineCounter;
    MineTimer* mineTimer;
    QPushButton* newGame;
    QTimer* gameClock;

    QIcon smileIcon = QIcon(QPixmap("/home/koshek/Desktop/bla/pictures/smile_emoji.png"));
    QIcon injuredIcon = QIcon(QPixmap("/home/koshek/Desktop/bla/pictures/injured_emoji.png"));
    QIcon sunglassesIcon = QIcon(QPixmap("/home/koshek/Desktop/bla/pictures/sunglasses_emoji.png"));

    QStateMachine fsm;
    QState* NewGameState;
    QState* GamingState;
    QState* WinnerState;
    QState* LoserState;
};
#endif // MAINWINDOW_H
