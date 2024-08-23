#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QPushButton>
#include <QTimer>
#include "field.h"
#include "minecounter.h"
#include "minetimer.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

signals:

    void victory();
    void game_over();
    void start();
    void new_game();


private slots:

private:
    Ui::Dialog *ui;

    void setupFSM();
    void initialize();

    Field* MineField;
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
    //max num of mines allowed for rowsxcols is rows*cols-9
    unsigned int Rows = 20, Cols = 20, Mines = 100;

    //void mousePressEvent(QMouseEvent* e);
};
#endif // DIALOG_H
