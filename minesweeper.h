#ifndef MINESWEEPER_H
#define MINESWEEPER_H

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

    int Rows, Cols, Mines;


    explicit minesweeper(QWidget *parent = nullptr);
    void setDifficulty(Difficulty difficulty, int num_rows, int num_cols, int num_mines);
    ~minesweeper();

private:
    Ui::minesweeper *ui;
    void init();
};

#endif // MINESWEEPER_H
