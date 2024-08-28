#ifndef DIALOG_H
#define DIALOG_H

#include "mainwindow.h"
#include "subdialog.h"

#include <QDialog>
#include <QPushButton>
#include <QPixmap>
#include <QPalette>
#include <QBrush>



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

private slots:
    void on_Easy_clicked();
    void on_Medium_clicked();
    void on_Hard_clicked();
    void on_Custom_clicked();

private:
    Ui::Dialog *ui;
    MainWindow* NewGame = new MainWindow;

    void resizeEvent(QResizeEvent* evt) override;

};
#endif // DIALOG_H
