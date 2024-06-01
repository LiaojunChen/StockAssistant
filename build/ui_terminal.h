/********************************************************************************
** Form generated from reading UI file 'terminal.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERMINAL_H
#define UI_TERMINAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Terminal
{
public:
    QLabel *label;
    QPushButton *pushButton;
    QTextEdit *textEdit;

    void setupUi(QWidget *Terminal)
    {
        if (Terminal->objectName().isEmpty())
            Terminal->setObjectName(QString::fromUtf8("Terminal"));
        Terminal->resize(621, 384);
        Terminal->setStyleSheet(QString::fromUtf8("background-color: rgb(232,252,242);"));
        label = new QLabel(Terminal);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(130, 200, 411, 41));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        pushButton = new QPushButton(Terminal);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 270, 155, 96));
        pushButton->setFont(font);
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        textEdit = new QTextEdit(Terminal);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(110, 20, 381, 161));
        textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));

        retranslateUi(Terminal);

        QMetaObject::connectSlotsByName(Terminal);
    } // setupUi

    void retranslateUi(QWidget *Terminal)
    {
        Terminal->setWindowTitle(QCoreApplication::translate("Terminal", "Form", nullptr));
        label->setText(QCoreApplication::translate("Terminal", "\350\257\267\351\207\215\346\226\260\345\220\257\345\212\250\347\250\213\345\272\217  \347\245\235\346\202\250\347\224\237\346\264\273\346\204\211\345\277\253\357\274\201", nullptr));
        pushButton->setText(QCoreApplication::translate("Terminal", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Terminal: public Ui_Terminal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERMINAL_H
