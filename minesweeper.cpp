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
    QFrame* MainFrame = new QFrame(this);
    QVBoxLayout* VerticalLayout = new QVBoxLayout;
    QHBoxLayout* HorizontalLayout = new QHBoxLayout;

    VerticalLayout->addLayout(HorizontalLayout);
    MainFrame->setLayout(VerticalLayout);

    delete MainFrame;
}

void minesweeper::setDifficulty(Difficulty difficulty, int num_rows, int num_cols, int num_mines){
    switch(difficulty){
    case easy:
        Rows = 8;
        Cols = 10;
        Mines = 10;
        break;

    case medium:
        Rows = 14;
        Cols = 18;
        Mines = 40;
        break;

    case hard:
        Rows = 22;
        Cols = 24;
        Mines = 99;
        break;

    case custom:
        Rows = num_rows;
        Cols = num_cols;
        Mines = num_mines;
        break;

    }
}
