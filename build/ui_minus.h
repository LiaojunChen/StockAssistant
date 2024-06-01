/********************************************************************************
** Form generated from reading UI file 'minus.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINUS_H
#define UI_MINUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Minus
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QLineEdit *stockamountinput;

    void setupUi(QWidget *Minus)
    {
        if (Minus->objectName().isEmpty())
            Minus->setObjectName(QString::fromUtf8("Minus"));
        Minus->resize(828, 512);
        Minus->setStyleSheet(QString::fromUtf8("background-color: rgb(232,252,242);"));
        pushButton = new QPushButton(Minus);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 90, 30));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        label = new QLabel(Minus);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 150, 241, 81));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        pushButton_2 = new QPushButton(Minus);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 400, 181, 71));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        stockamountinput = new QLineEdit(Minus);
        stockamountinput->setObjectName(QString::fromUtf8("stockamountinput"));
        stockamountinput->setGeometry(QRect(440, 170, 241, 51));
        stockamountinput->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));

        retranslateUi(Minus);

        QMetaObject::connectSlotsByName(Minus);
    } // setupUi

    void retranslateUi(QWidget *Minus)
    {
        Minus->setWindowTitle(QCoreApplication::translate("Minus", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Minus", "<-\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("Minus", "\350\276\223\345\205\245\345\207\217\344\273\223\351\207\221\351\242\235\357\277\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Minus", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Minus: public Ui_Minus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINUS_H
