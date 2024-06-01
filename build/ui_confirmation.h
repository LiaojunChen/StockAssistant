/********************************************************************************
** Form generated from reading UI file 'confirmation.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMATION_H
#define UI_CONFIRMATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Confirmation
{
public:
    QLabel *label;
    QTextEdit *confirmation;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QWidget *Confirmation)
    {
        if (Confirmation->objectName().isEmpty())
            Confirmation->setObjectName(QString::fromUtf8("Confirmation"));
        Confirmation->resize(621, 384);
        QFont font;
        font.setPointSize(9);
        Confirmation->setFont(font);
        Confirmation->setStyleSheet(QString::fromUtf8("background-color: rgb(232,252,242);"));
        label = new QLabel(Confirmation);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 40, 491, 51));
        QFont font1;
        font1.setPointSize(15);
        label->setFont(font1);
        confirmation = new QTextEdit(Confirmation);
        confirmation->setObjectName(QString::fromUtf8("confirmation"));
        confirmation->setGeometry(QRect(80, 99, 431, 131));
        confirmation->setStyleSheet(QString::fromUtf8("background-color: rgb(255,255,255);"));
        horizontalLayoutWidget = new QWidget(Confirmation);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(80, 250, 431, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(horizontalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(horizontalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(0,132,112);color: rgb(255,255,255);"));

        horizontalLayout->addWidget(pushButton);


        retranslateUi(Confirmation);

        QMetaObject::connectSlotsByName(Confirmation);
    } // setupUi

    void retranslateUi(QWidget *Confirmation)
    {
        Confirmation->setWindowTitle(QCoreApplication::translate("Confirmation", "Form", nullptr));
        label->setText(QCoreApplication::translate("Confirmation", "\347\241\256\350\256\244\346\202\250\350\246\201\346\211\247\350\241\214\347\232\204\346\223\215\344\275\234\357\274\232", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Confirmation", "\347\241\256\350\256\244", nullptr));
        pushButton->setText(QCoreApplication::translate("Confirmation", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Confirmation: public Ui_Confirmation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMATION_H
