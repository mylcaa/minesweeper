/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QPushButton *Easy;
    QPushButton *Medium;
    QPushButton *Hard;
    QPushButton *Custom;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(800, 600);
        gridLayout = new QGridLayout(Dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(50);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetFixedSize);
        Easy = new QPushButton(Dialog);
        Easy->setObjectName(QString::fromUtf8("Easy"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(Easy->sizePolicy().hasHeightForWidth());
        Easy->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Nimbus Mono PS [urw]"));
        font.setPointSize(17);
        font.setBold(false);
        Easy->setFont(font);

        verticalLayout->addWidget(Easy);

        Medium = new QPushButton(Dialog);
        Medium->setObjectName(QString::fromUtf8("Medium"));
        sizePolicy.setHeightForWidth(Medium->sizePolicy().hasHeightForWidth());
        Medium->setSizePolicy(sizePolicy);
        Medium->setFont(font);

        verticalLayout->addWidget(Medium);

        Hard = new QPushButton(Dialog);
        Hard->setObjectName(QString::fromUtf8("Hard"));
        sizePolicy.setHeightForWidth(Hard->sizePolicy().hasHeightForWidth());
        Hard->setSizePolicy(sizePolicy);
        Hard->setFont(font);

        verticalLayout->addWidget(Hard);

        Custom = new QPushButton(Dialog);
        Custom->setObjectName(QString::fromUtf8("Custom"));
        sizePolicy.setHeightForWidth(Custom->sizePolicy().hasHeightForWidth());
        Custom->setSizePolicy(sizePolicy);
        Custom->setFont(font);

        verticalLayout->addWidget(Custom);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 2);

        verticalLayout_2->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 3);
        verticalLayout_2->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        Easy->setText(QCoreApplication::translate("Dialog", "EASY", nullptr));
        Medium->setText(QCoreApplication::translate("Dialog", "MEDIUM", nullptr));
        Hard->setText(QCoreApplication::translate("Dialog", "HARD", nullptr));
        Custom->setText(QCoreApplication::translate("Dialog", "CUSTOM", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
