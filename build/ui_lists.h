/********************************************************************************
** Form generated from reading UI file 'lists.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTS_H
#define UI_LISTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Lists
{
public:
    QPushButton *switch_2;
    QComboBox *comboBox;
    QLabel *label;
    QTextEdit *textEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_6;
    QScrollArea *brief;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label_5;
    QTextEdit *stockname;
    QTextEdit *profitandloss;
    QTextEdit *latestprofitandloss;

    void setupUi(QWidget *Lists)
    {
        if (Lists->objectName().isEmpty())
            Lists->setObjectName(QString::fromUtf8("Lists"));
        Lists->resize(1657, 1024);
        QFont font;
        font.setPointSize(12);
        Lists->setFont(font);
        Lists->setStyleSheet(QString::fromUtf8("background-color: rgb(232,252,242);"));
        switch_2 = new QPushButton(Lists);
        switch_2->setObjectName(QString::fromUtf8("switch_2"));
        switch_2->setGeometry(QRect(10, 20, 141, 71));
        switch_2->setFont(font);
        switch_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        comboBox = new QComboBox(Lists);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(460, 170, 221, 51));
        label = new QLabel(Lists);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 170, 241, 41));
        textEdit = new QTextEdit(Lists);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(20, 230, 801, 751));
        scrollArea = new QScrollArea(Lists);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(980, 170, 661, 1071));
        scrollArea->setMinimumSize(QSize(661, 1071));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 659, 1069));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(680, 20, 141, 41));
        brief = new QScrollArea(scrollAreaWidgetContents);
        brief->setObjectName(QString::fromUtf8("brief"));
        brief->setGeometry(QRect(0, 0, 661, 851));
        brief->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        brief->setWidgetResizable(false);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1560, 3000));
        label_2 = new QLabel(scrollAreaWidgetContents_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 30, 141, 41));
        label_4 = new QLabel(scrollAreaWidgetContents_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(260, 30, 141, 41));
        label_5 = new QLabel(scrollAreaWidgetContents_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(460, 30, 141, 41));
        stockname = new QTextEdit(scrollAreaWidgetContents_2);
        stockname->setObjectName(QString::fromUtf8("stockname"));
        stockname->setGeometry(QRect(0, 90, 251, 1261));
        profitandloss = new QTextEdit(scrollAreaWidgetContents_2);
        profitandloss->setObjectName(QString::fromUtf8("profitandloss"));
        profitandloss->setGeometry(QRect(250, 90, 191, 1261));
        latestprofitandloss = new QTextEdit(scrollAreaWidgetContents_2);
        latestprofitandloss->setObjectName(QString::fromUtf8("latestprofitandloss"));
        latestprofitandloss->setGeometry(QRect(440, 90, 201, 1341));
        brief->setWidget(scrollAreaWidgetContents_2);
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(Lists);

        QMetaObject::connectSlotsByName(Lists);
    } // setupUi

    void retranslateUi(QWidget *Lists)
    {
        Lists->setWindowTitle(QCoreApplication::translate("Lists", "Form", nullptr));
        switch_2->setText(QCoreApplication::translate("Lists", "\346\210\221\347\232\204\350\202\241\347\245\250", nullptr));
        label->setText(QCoreApplication::translate("Lists", "<html><head/><body><p align=\"center\">\346\214\207\346\225\260\350\265\260\345\212\277</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Lists", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\346\210\220\346\234\254/\347\216\260\344\273\267</span></p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("Lists", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\350\202\241\347\245\250\345\220\215\347\247\260</span></p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("Lists", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\346\265\256\345\212\250\347\233\210\344\272\217</span></p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("Lists", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\346\234\200\346\226\260\346\266\250\350\267\214</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Lists: public Ui_Lists {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTS_H
