/********************************************************************************
** Form generated from reading UI file 'subdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBDIALOG_H
#define UI_SUBDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Subdialog
{
public:
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *RowsLine;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *ColsLine;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *MinesLine;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;

    void setupUi(QDialog *Subdialog)
    {
        if (Subdialog->objectName().isEmpty())
            Subdialog->setObjectName(QString::fromUtf8("Subdialog"));
        Subdialog->resize(312, 231);
        widget = new QWidget(Subdialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(9, 9, 291, 211));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(20);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Nimbus Mono PS [urw]"));
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        RowsLine = new QLineEdit(widget);
        RowsLine->setObjectName(QString::fromUtf8("RowsLine"));

        horizontalLayout->addWidget(RowsLine);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setTextFormat(Qt::AutoText);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        ColsLine = new QLineEdit(widget);
        ColsLine->setObjectName(QString::fromUtf8("ColsLine"));

        horizontalLayout_2->addWidget(ColsLine);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setTextFormat(Qt::AutoText);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        MinesLine = new QLineEdit(widget);
        MinesLine->setObjectName(QString::fromUtf8("MinesLine"));

        horizontalLayout_3->addWidget(MinesLine);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 10);
        horizontalLayout_4->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_4);


        retranslateUi(Subdialog);

        QMetaObject::connectSlotsByName(Subdialog);
    } // setupUi

    void retranslateUi(QDialog *Subdialog)
    {
        Subdialog->setWindowTitle(QCoreApplication::translate("Subdialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Subdialog", "  ROWS:   ", nullptr));
        label_2->setText(QCoreApplication::translate("Subdialog", "  COLS:   ", nullptr));
        label_3->setText(QCoreApplication::translate("Subdialog", "NUM MINES:", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Subdialog", "BACK", nullptr));
        pushButton->setText(QCoreApplication::translate("Subdialog", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Subdialog: public Ui_Subdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBDIALOG_H
