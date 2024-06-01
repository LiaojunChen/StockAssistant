/********************************************************************************
** Form generated from reading UI file 'core.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CORE_H
#define UI_CORE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Core
{
public:
    QPushButton *Switch_Mode_Button;
    QLabel *label_2;
    QTextEdit *chatoutput;
    QLabel *label_3;
    QTextEdit *finnewsoutput;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_9;
    QLabel *label_6;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QTextEdit *stockname;
    QTextEdit *positionamount;
    QTextEdit *stockprice;
    QTextEdit *profitandlossrate;
    QTextEdit *latestprofitandloss;
    QPushButton *GPTbutton;
    QPushButton *switchbutton_2;
    QPushButton *Switch_Mode_Button_2;
    QPushButton *pushButton_3;
    QPlainTextEdit *chatinput;
    QScrollBar *verticalScrollBar;

    void setupUi(QWidget *Core)
    {
        if (Core->objectName().isEmpty())
            Core->setObjectName(QString::fromUtf8("Core"));
        Core->resize(1693, 1055);
        Core->setStyleSheet(QString::fromUtf8("background-color: rgb(232,252,242);"));
        Switch_Mode_Button = new QPushButton(Core);
        Switch_Mode_Button->setObjectName(QString::fromUtf8("Switch_Mode_Button"));
        Switch_Mode_Button->setGeometry(QRect(10, 30, 181, 101));
        Switch_Mode_Button->setMinimumSize(QSize(181, 0));
        QFont font;
        font.setPointSize(12);
        Switch_Mode_Button->setFont(font);
        Switch_Mode_Button->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        label_2 = new QLabel(Core);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1230, 30, 461, 51));
        QFont font1;
        font1.setPointSize(15);
        label_2->setFont(font1);
        chatoutput = new QTextEdit(Core);
        chatoutput->setObjectName(QString::fromUtf8("chatoutput"));
        chatoutput->setGeometry(QRect(970, 170, 711, 461));
        chatoutput->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        label_3 = new QLabel(Core);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1290, 650, 421, 51));
        label_3->setFont(font1);
        finnewsoutput = new QTextEdit(Core);
        finnewsoutput->setObjectName(QString::fromUtf8("finnewsoutput"));
        finnewsoutput->setGeometry(QRect(970, 710, 711, 331));
        finnewsoutput->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        scrollArea = new QScrollArea(Core);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 160, 931, 891));
        scrollArea->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, -722, 1560, 3000));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(50, 40, 141, 41));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(250, 40, 141, 81));
        label_11 = new QLabel(scrollAreaWidgetContents);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(740, 40, 131, 41));
        label_12 = new QLabel(scrollAreaWidgetContents);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(580, 40, 131, 41));
        label_13 = new QLabel(scrollAreaWidgetContents);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(430, 40, 121, 81));
        stockname = new QTextEdit(scrollAreaWidgetContents);
        stockname->setObjectName(QString::fromUtf8("stockname"));
        stockname->setGeometry(QRect(10, 140, 231, 1341));
        positionamount = new QTextEdit(scrollAreaWidgetContents);
        positionamount->setObjectName(QString::fromUtf8("positionamount"));
        positionamount->setGeometry(QRect(240, 140, 171, 1331));
        stockprice = new QTextEdit(scrollAreaWidgetContents);
        stockprice->setObjectName(QString::fromUtf8("stockprice"));
        stockprice->setGeometry(QRect(410, 140, 171, 1331));
        profitandlossrate = new QTextEdit(scrollAreaWidgetContents);
        profitandlossrate->setObjectName(QString::fromUtf8("profitandlossrate"));
        profitandlossrate->setGeometry(QRect(580, 140, 141, 1271));
        latestprofitandloss = new QTextEdit(scrollAreaWidgetContents);
        latestprofitandloss->setObjectName(QString::fromUtf8("latestprofitandloss"));
        latestprofitandloss->setGeometry(QRect(720, 140, 161, 1261));
        scrollArea->setWidget(scrollAreaWidgetContents);
        GPTbutton = new QPushButton(Core);
        GPTbutton->setObjectName(QString::fromUtf8("GPTbutton"));
        GPTbutton->setGeometry(QRect(1590, 100, 81, 41));
        switchbutton_2 = new QPushButton(Core);
        switchbutton_2->setObjectName(QString::fromUtf8("switchbutton_2"));
        switchbutton_2->setGeometry(QRect(666, 30, 171, 101));
        switchbutton_2->setFont(font);
        switchbutton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        Switch_Mode_Button_2 = new QPushButton(Core);
        Switch_Mode_Button_2->setObjectName(QString::fromUtf8("Switch_Mode_Button_2"));
        Switch_Mode_Button_2->setGeometry(QRect(240, 30, 181, 101));
        Switch_Mode_Button_2->setFont(font);
        Switch_Mode_Button_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        pushButton_3 = new QPushButton(Core);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(450, 30, 181, 101));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        chatinput = new QPlainTextEdit(Core);
        chatinput->setObjectName(QString::fromUtf8("chatinput"));
        chatinput->setGeometry(QRect(970, 90, 611, 70));
        verticalScrollBar = new QScrollBar(Core);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setGeometry(QRect(1660, 170, 21, 461));
        verticalScrollBar->setOrientation(Qt::Vertical);

        retranslateUi(Core);

        QMetaObject::connectSlotsByName(Core);
    } // setupUi

    void retranslateUi(QWidget *Core)
    {
        Core->setWindowTitle(QCoreApplication::translate("Core", "Form", nullptr));
#if QT_CONFIG(whatsthis)
        Switch_Mode_Button->setWhatsThis(QCoreApplication::translate("Core", "<html><head/><body><p align=\"center\">\350\241\214\346\203\205\350\265\204\350\256\257</p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        Switch_Mode_Button->setText(QCoreApplication::translate("Core", "\350\241\214\346\203\205\350\265\204\350\256\257", nullptr));
        label_2->setText(QCoreApplication::translate("Core", "GPT\347\232\204\346\212\225\350\265\204\345\273\272\350\256\256", nullptr));
        label_3->setText(QCoreApplication::translate("Core", "\350\264\242\347\273\217\346\226\260\351\227\273\345\217\212\345\275\242\345\212\277\345\210\206\346\236\220", nullptr));
        label_9->setText(QCoreApplication::translate("Core", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\350\202\241\347\245\250\345\220\215\347\247\260</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("Core", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\346\214\201\344\273\223\351\207\221\351\242\235/</span></p><p align=\"center\"><span style=\" font-size:16pt;\">\346\214\201\344\273\223\346\224\266\347\233\212</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("Core", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\346\234\200\346\226\260\346\266\250\350\267\214</span></p></body></html>", nullptr));
        label_12->setText(QCoreApplication::translate("Core", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\346\224\266\347\233\212\347\216\207</span></p></body></html>", nullptr));
        label_13->setText(QCoreApplication::translate("Core", "<html><head/><body><p align=\"center\"><span style=\" font-size:16pt;\">\347\216\260\344\273\267/</span></p><p align=\"center\"><span style=\" font-size:16pt;\">\346\210\220\346\234\254</span></p></body></html>", nullptr));
        stockname->setHtml(QCoreApplication::translate("Core", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        positionamount->setHtml(QCoreApplication::translate("Core", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        GPTbutton->setText(QCoreApplication::translate("Core", "\342\206\221", nullptr));
        switchbutton_2->setText(QCoreApplication::translate("Core", "\344\277\256\346\224\271\346\214\201\344\273\223", nullptr));
        Switch_Mode_Button_2->setText(QCoreApplication::translate("Core", "\350\202\241\347\245\250\346\237\245\350\257\242", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Core", "\344\271\260\345\205\245\346\226\260\350\202\241\347\245\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Core: public Ui_Core {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CORE_H
