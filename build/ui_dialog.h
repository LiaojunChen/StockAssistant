/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QLabel *label_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(1657, 1024);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(400, 120, 1091, 101));
        QFont font;
        font.setPointSize(25);
        label->setFont(font);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(440, 280, 991, 141));
        QFont font1;
        font1.setPointSize(22);
        label_2->setFont(font1);
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(660, 510, 271, 131));
        QFont font2;
        font2.setPointSize(11);
        pushButton->setFont(font2);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(600, 750, 991, 141));
        QFont font3;
        font3.setPointSize(17);
        label_3->setFont(font3);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\346\254\242\350\277\216\346\235\245\345\210\260\345\237\272\344\272\216GPT\347\232\204\344\270\252\344\272\272\350\202\241\347\245\250\344\272\244\346\230\223\347\250\213\345\272\217\357\274\201", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "OpenAI GPT    \344\270\272\346\202\250\347\232\204\350\264\242\345\257\214\344\277\235\351\251\276\346\212\244\350\210\252\357\274\201", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "\347\202\271\345\207\273\344\273\245\345\274\200\345\247\213", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "\346\212\225\350\265\204\346\234\211\351\243\216\351\231\251\357\274\201 \345\205\245\345\270\202\351\234\200\350\260\250\346\205\216\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
