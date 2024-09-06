#include "subdialog.h"
#include "ui_subdialog.h"
#include "dialog.h"

Subdialog::Subdialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Subdialog)
{
    ui->setupUi(this);
    this->setWindowTitle("SETUP CUSTOM GAME");
    this->setStyleSheet("QLineEdit{color: rgb(200, 200, 200);}");

    ui->RowsLine->setText("∈[1, 50]");
    ui->ColsLine->setText("∈[1, 50]");
    ui->MinesLine->setText("∈[1, rows*cols-10]");
}

Subdialog::~Subdialog()
{
    delete ui;
}

void Subdialog::on_pushButton_clicked()
{
    rows = ui->RowsLine->text().toInt();
    cols = ui->ColsLine->text().toInt();
    num_mines = ui->MinesLine->text().toInt();

    if((rows > 0 && rows <= 50) && (cols > 0 && cols <= 50) && (num_mines >= 1 && num_mines <= cols*rows-10)){
        this->close();

        NewGame = new MainWindow(rows, cols, num_mines, this);
        this->close();
        NewGame -> show();

    }else{
        WarningWindow = new warning;
        WarningWindow -> show();
    }
}


void Subdialog::on_RowsLine_textEdited()
{
    if(init_rows){
        ui->RowsLine->clear();
        ui->RowsLine->setStyleSheet("QLineEdit{color: black;}");

        init_rows = 0;
    }
}

void Subdialog::on_ColsLine_textEdited()
{
    if(init_cols){
        ui->ColsLine->clear();
        ui->ColsLine->setStyleSheet("QLineEdit{color: black;}");

        init_cols = 0;
    }
}

void Subdialog::on_MinesLine_textEdited()
{
    if(init_mines){
        ui->MinesLine->clear();
        ui->MinesLine->setStyleSheet("QLineEdit{color: black;}");

        init_mines = 0;
    }
}


void Subdialog::on_pushButton_2_clicked()
{
    QDialog* Menu = new Dialog;
    Menu  -> show();
    this->close();
}

