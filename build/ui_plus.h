/********************************************************************************
** Form generated from reading UI file 'plus.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUS_H
#define UI_PLUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Plus
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *stockamountinput;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Plus)
    {
        if (Plus->objectName().isEmpty())
            Plus->setObjectName(QString::fromUtf8("Plus"));
        Plus->resize(828, 512);
        Plus->setStyleSheet(QString::fromUtf8("background-color: rgb(232,252,242);"));
        pushButton = new QPushButton(Plus);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 90, 30));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        label = new QLabel(Plus);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 130, 241, 81));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        stockamountinput = new QLineEdit(Plus);
        stockamountinput->setObjectName(QString::fromUtf8("stockamountinput"));
        stockamountinput->setGeometry(QRect(410, 150, 241, 51));
        stockamountinput->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        pushButton_2 = new QPushButton(Plus);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 360, 181, 71));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));

        retranslateUi(Plus);

        QMetaObject::connectSlotsByName(Plus);
    } // setupUi

    void retranslateUi(QWidget *Plus)
    {
        Plus->setWindowTitle(QCoreApplication::translate("Plus", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Plus", "<-\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("Plus", "\350\276\223\345\205\245\345\212\240\344\273\223\350\202\241\346\225\260", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Plus", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Plus: public Ui_Plus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUS_H
