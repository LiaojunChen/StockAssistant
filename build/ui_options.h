/********************************************************************************
** Form generated from reading UI file 'options.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTIONS_H
#define UI_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Options
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *plus;
    QPushButton *minus;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QComboBox *comboBoxstockname;

    void setupUi(QWidget *Options)
    {
        if (Options->objectName().isEmpty())
            Options->setObjectName(QString::fromUtf8("Options"));
        Options->resize(828, 512);
        Options->setStyleSheet(QString::fromUtf8("background-color: rgb(232,252,242);"));
        verticalLayoutWidget = new QWidget(Options);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(310, 220, 361, 261));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        plus = new QPushButton(verticalLayoutWidget);
        plus->setObjectName(QString::fromUtf8("plus"));
        QFont font;
        font.setPointSize(12);
        plus->setFont(font);
        plus->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));

        verticalLayout->addWidget(plus);

        minus = new QPushButton(verticalLayoutWidget);
        minus->setObjectName(QString::fromUtf8("minus"));
        minus->setFont(font);
        minus->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));

        verticalLayout->addWidget(minus);

        label = new QLabel(Options);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 290, 251, 91));
        QFont font1;
        font1.setPointSize(13);
        label->setFont(font1);
        label->setLineWidth(1);
        label->setWordWrap(false);
        label->setMargin(14);
        label->setIndent(5);
        label->setOpenExternalLinks(false);
        pushButton = new QPushButton(Options);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 90, 30));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));
        label_2 = new QLabel(Options);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 60, 401, 91));
        label_2->setFont(font1);
        label_2->setLineWidth(1);
        label_2->setWordWrap(false);
        label_2->setMargin(14);
        label_2->setIndent(5);
        label_2->setOpenExternalLinks(false);
        comboBoxstockname = new QComboBox(Options);
        comboBoxstockname->addItem(QString());
        comboBoxstockname->setObjectName(QString::fromUtf8("comboBoxstockname"));
        comboBoxstockname->setGeometry(QRect(360, 80, 261, 51));
        comboBoxstockname->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));

        retranslateUi(Options);

        QMetaObject::connectSlotsByName(Options);
    } // setupUi

    void retranslateUi(QWidget *Options)
    {
        Options->setWindowTitle(QCoreApplication::translate("Options", "Form", nullptr));
        plus->setText(QCoreApplication::translate("Options", "\345\212\240\344\273\223", nullptr));
        minus->setText(QCoreApplication::translate("Options", "\345\207\217\344\273\223", nullptr));
        label->setText(QCoreApplication::translate("Options", "\351\200\211\346\213\251\346\211\247\350\241\214\347\232\204\346\223\215\344\275\234", nullptr));
        pushButton->setText(QCoreApplication::translate("Options", "<-\350\277\224\345\233\236", nullptr));
        label_2->setText(QCoreApplication::translate("Options", "\351\200\211\346\213\251\346\211\247\350\241\214\346\223\215\344\275\234\347\232\204\350\202\241\347\245\250", nullptr));
        comboBoxstockname->setItemText(0, QString());

    } // retranslateUi

};

namespace Ui {
    class Options: public Ui_Options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTIONS_H
