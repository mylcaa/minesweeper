#include "warning.h"
#include "ui_warning.h"

warning::warning(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::warning)
{
    ui->setupUi(this);
    this->setWindowTitle("NOTE:");

    QPixmap pixmap("/home/koshek/Desktop/final_minesweeper/pictures/warning_sign.jpg");
    ui->label->setPixmap(pixmap);
}

warning::~warning()
{
    delete ui;
}
