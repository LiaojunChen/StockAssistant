/********************************************************************************
** Form generated from reading UI file 'purchase.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PURCHASE_H
#define UI_PURCHASE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Purchase
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *stockamountinput;
    QLabel *label_2;
    QPushButton *pushButton_2;
    QLineEdit *stocknumberinput_2;

    void setupUi(QWidget *Purchase)
    {
        if (Purchase->objectName().isEmpty())
            Purchase->setObjectName(QString::fromUtf8("Purchase"));
        Purchase->resize(828, 512);
        Purchase->setStyleSheet(QString::fromUtf8("background-color: rgb(232,252,242);"));
        pushButton = new QPushButton(Purchase);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 90, 30));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        label = new QLabel(Purchase);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 180, 211, 81));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        stockamountinput = new QLineEdit(Purchase);
        stockamountinput->setObjectName(QString::fromUtf8("stockamountinput"));
        stockamountinput->setGeometry(QRect(430, 190, 241, 61));
        stockamountinput->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        label_2 = new QLabel(Purchase);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(230, 90, 181, 60));
        QFont font1;
        font1.setPointSize(13);
        label_2->setFont(font1);
        pushButton_2 = new QPushButton(Purchase);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 360, 181, 71));
        pushButton_2->setFont(font);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        stocknumberinput_2 = new QLineEdit(Purchase);
        stocknumberinput_2->setObjectName(QString::fromUtf8("stocknumberinput_2"));
        stocknumberinput_2->setGeometry(QRect(430, 90, 241, 71));

        retranslateUi(Purchase);

        QMetaObject::connectSlotsByName(Purchase);
    } // setupUi

    void retranslateUi(QWidget *Purchase)
    {
        Purchase->setWindowTitle(QCoreApplication::translate("Purchase", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Purchase", "<-\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("Purchase", "\350\257\267\350\276\223\345\205\245\350\264\255\344\271\260\350\202\241\346\225\260", nullptr));
        label_2->setText(QCoreApplication::translate("Purchase", "\350\257\267\350\276\223\345\205\245\350\202\241\347\245\250\344\273\243\347\240\201", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Purchase", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Purchase: public Ui_Purchase {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PURCHASE_H
