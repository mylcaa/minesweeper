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
    QPixmap bkgnd("/home/koshek/Desktop/moj_minesweeper/minesweeper/pictures/start_bckgrnd.png");
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

    NewGame = new MainWindow(8, 10, 10, this);

    this->close();
    NewGame -> show();
}

void Dialog::on_Medium_clicked()
{
    NewGame = new MainWindow(14, 18, 40, this);

    this->close();
    NewGame -> show();
}

void Dialog::on_Hard_clicked()
{
    NewGame = new MainWindow(22, 24, 99, this);

    this->close();
    NewGame -> show();
}

void Dialog::on_Custom_clicked()
{
    this->close();

    //Subdialog* Sub = new Subdialog;
    //Sub -> show();
}

