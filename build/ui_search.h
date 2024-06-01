/********************************************************************************
** Form generated from reading UI file 'search.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCH_H
#define UI_SEARCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Search
{
public:
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;
    QTextEdit *stocknameoutput;
    QLabel *label_4;
    QTextEdit *stockpriceoutput;
    QTextEdit *stockrateoutput;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *stocknumberinput;

    void setupUi(QWidget *Search)
    {
        if (Search->objectName().isEmpty())
            Search->setObjectName(QString::fromUtf8("Search"));
        Search->resize(828, 512);
        Search->setStyleSheet(QString::fromUtf8("background-color: rgb(232,252,242);"));
        label_2 = new QLabel(Search);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 60, 181, 60));
        QFont font;
        font.setPointSize(13);
        label_2->setFont(font);
        pushButton = new QPushButton(Search);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 90, 30));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        label_3 = new QLabel(Search);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 140, 181, 60));
        QFont font1;
        font1.setPointSize(12);
        label_3->setFont(font1);
        stocknameoutput = new QTextEdit(Search);
        stocknameoutput->setObjectName(QString::fromUtf8("stocknameoutput"));
        stocknameoutput->setGeometry(QRect(350, 140, 371, 51));
        stocknameoutput->setFont(font1);
        stocknameoutput->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        label_4 = new QLabel(Search);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(160, 220, 181, 60));
        label_4->setFont(font1);
        stockpriceoutput = new QTextEdit(Search);
        stockpriceoutput->setObjectName(QString::fromUtf8("stockpriceoutput"));
        stockpriceoutput->setGeometry(QRect(350, 220, 181, 51));
        stockpriceoutput->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        stockrateoutput = new QTextEdit(Search);
        stockrateoutput->setObjectName(QString::fromUtf8("stockrateoutput"));
        stockrateoutput->setGeometry(QRect(350, 300, 181, 51));
        stockrateoutput->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        label_5 = new QLabel(Search);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(160, 300, 181, 60));
        label_5->setFont(font1);
        pushButton_2 = new QPushButton(Search);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(160, 380, 181, 71));
        QFont font2;
        font2.setPointSize(15);
        pushButton_2->setFont(font2);
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        pushButton_3 = new QPushButton(Search);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(580, 60, 121, 61));
        stocknumberinput = new QLineEdit(Search);
        stocknumberinput->setObjectName(QString::fromUtf8("stocknumberinput"));
        stocknumberinput->setGeometry(QRect(360, 60, 201, 61));

        retranslateUi(Search);

        QMetaObject::connectSlotsByName(Search);
    } // setupUi

    void retranslateUi(QWidget *Search)
    {
        Search->setWindowTitle(QCoreApplication::translate("Search", "Form", nullptr));
        label_2->setText(QCoreApplication::translate("Search", "\350\276\223\345\205\245\350\202\241\347\245\250\344\273\243\347\240\201", nullptr));
        pushButton->setText(QCoreApplication::translate("Search", "<-\350\277\224\345\233\236", nullptr));
        label_3->setText(QCoreApplication::translate("Search", "\350\202\241\347\245\250\345\220\215\347\247\260", nullptr));
        label_4->setText(QCoreApplication::translate("Search", "\345\215\225\350\202\241\344\273\267\346\240\274", nullptr));
        label_5->setText(QCoreApplication::translate("Search", "\346\234\200\346\226\260\346\266\250\350\267\214\345\271\205\345\272\246/\346\257\224\347\216\207", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Search", "\345\273\272\344\273\223", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Search", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Search: public Ui_Search {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCH_H
