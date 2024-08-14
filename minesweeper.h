#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include "subdialog.h"
#include <QMainWindow>
#include <QFrame>
#include <QVBoxLayout>
#include <QHBoxLayout>

namespace Ui {
class minesweeper;
}

class minesweeper : public QMainWindow
{
    Q_OBJECT

public:

    enum Difficulty
    {
        easy,
        medium,
        hard,
        custom,
    };

    int rows, cols, num_mines;


    explicit minesweeper(QWidget *parent = nullptr);
    void setDifficulty(Difficulty difficulty);
    ~minesweeper();

private:
    Ui::minesweeper *ui;
    QDialog* Sub = new Subdialog;

    void init();
};

#endif // MINESWEEPER_H
