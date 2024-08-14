#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->setWindowTitle("MINESWEEPER");
    this->setStyleSheet("QPushButton::hover{color: #8399ff;}");
}

void Dialog::resizeEvent(QResizeEvent* evt)
{
    QPixmap bkgnd("/home/koshek/Desktop/moj_minesweeper/pictures/start_bckgrnd.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Window, bkgnd);
    this->setPalette(palette);
}


Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_Easy_clicked()
{
    this->close();

    //NewGame -> setDifficulty(easy);
    //NewGame -> show();
}

void Dialog::on_Medium_clicked()
{
    this->close();

    //NewGame -> setDifficulty(medium);
    //NewGame -> show();
}

void Dialog::on_Hard_clicked()
{
    this->close();

    //NewGame -> setDifficulty(medium);
    //NewGame -> show();
}

void Dialog::on_Custom_clicked()
{
    this->close();

    NewGame = new minesweeper;
    NewGame -> setDifficulty(minesweeper::Difficulty::custom);
}

