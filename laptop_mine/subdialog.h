#ifndef SUBDIALOG_H
#define SUBDIALOG_H

#include "warning.h"
#include "mainwindow.h"

#include <QDialog>


namespace Ui {
class Subdialog;
}

class Subdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Subdialog(QWidget *parent = nullptr);
    ~Subdialog();

    int rows, cols, num_mines;
    int init_rows = 1, init_cols = 1, init_mines = 1;

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_RowsLine_textEdited();
    void on_ColsLine_textEdited();
    void on_MinesLine_textEdited();


private:
    Ui::Subdialog *ui;
    warning* WarningWindow;
    MainWindow* NewGame;
};

#endif // SUBDIALOG_H
