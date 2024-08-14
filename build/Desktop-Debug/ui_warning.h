/********************************************************************************
** Form generated from reading UI file 'warning.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WARNING_H
#define UI_WARNING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_warning
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *warning)
    {
        if (warning->objectName().isEmpty())
            warning->setObjectName(QString::fromUtf8("warning"));
        warning->resize(307, 92);
        label = new QLabel(warning);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 20, 71, 61));
        label->setPixmap(QPixmap(QString::fromUtf8("pictures/warning_sign.jpg")));
        label->setScaledContents(true);
        label_2 = new QLabel(warning);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 0, 201, 91));
        QFont font;
        font.setFamily(QString::fromUtf8("Nimbus Mono PS [urw]"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(warning);

        QMetaObject::connectSlotsByName(warning);
    } // setupUi

    void retranslateUi(QDialog *warning)
    {
        warning->setWindowTitle(QCoreApplication::translate("warning", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("warning", "WRONG DIMENSIONS", nullptr));
    } // retranslateUi

};

namespace Ui {
    class warning: public Ui_warning {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WARNING_H
