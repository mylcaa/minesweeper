/********************************************************************************
** Form generated from reading UI file 'minesweeper.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINESWEEPER_H
#define UI_MINESWEEPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_minesweeper
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *minesweeper)
    {
        if (minesweeper->objectName().isEmpty())
            minesweeper->setObjectName(QString::fromUtf8("minesweeper"));
        minesweeper->resize(800, 600);
        centralwidget = new QWidget(minesweeper);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        minesweeper->setCentralWidget(centralwidget);
        menubar = new QMenuBar(minesweeper);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 23));
        minesweeper->setMenuBar(menubar);
        statusbar = new QStatusBar(minesweeper);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        minesweeper->setStatusBar(statusbar);

        retranslateUi(minesweeper);

        QMetaObject::connectSlotsByName(minesweeper);
    } // setupUi

    void retranslateUi(QMainWindow *minesweeper)
    {
        minesweeper->setWindowTitle(QCoreApplication::translate("minesweeper", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class minesweeper: public Ui_minesweeper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINESWEEPER_H
