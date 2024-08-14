#include "minesweeper.h"
#include "ui_minesweeper.h"

minesweeper::minesweeper(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::minesweeper)
{
    ui->setupUi(this);
    this->layout()->setSizeConstraint(QLayout::SetFixedSize);
}

minesweeper::~minesweeper()
{
    delete ui;
}

void minesweeper:: init(){
    QFrame* newFrame = new QFrame(this);
    QVBoxLayout* RowsLayout = new QVBoxLayout;
    QHBoxLayout* ColsLayout = new QHBoxLayout;

    RowsLayout->addLayout(ColsLayout);
    newFrame->setLayout(RowsLayout);

    delete newFrame;
}

void minesweeper::setDifficulty(Difficulty difficulty){

    switch(difficulty){
    case easy:
        rows = 8;
        cols = 10;
        num_mines = 10;
        break;

    case medium:
        rows = 14;
        cols = 18;
        num_mines = 40;
        break;

    case hard:
        rows = 22;
        cols = 24;
        num_mines = 99;
        break;

    case custom:
        Sub -> show();
        break;

    }

}
