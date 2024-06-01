/********************************************************************************
** Form generated from reading UI file 'switch.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SWITCH_H
#define UI_SWITCH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Switch
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QComboBox *comboBox;

    void setupUi(QWidget *Switch)
    {
        if (Switch->objectName().isEmpty())
            Switch->setObjectName(QString::fromUtf8("Switch"));
        Switch->resize(828, 512);
        pushButton = new QPushButton(Switch);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 90, 30));
        label = new QLabel(Switch);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 150, 241, 81));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);
        pushButton_2 = new QPushButton(Switch);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(360, 420, 181, 71));
        pushButton_2->setFont(font);
        lineEdit = new QLineEdit(Switch);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(440, 170, 241, 51));
        label_4 = new QLabel(Switch);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(178, 59, 239, 81));
        label_4->setFont(font);
        comboBox = new QComboBox(Switch);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(438, 80, 241, 41));

        retranslateUi(Switch);

        QMetaObject::connectSlotsByName(Switch);
    } // setupUi

    void retranslateUi(QWidget *Switch)
    {
        Switch->setWindowTitle(QCoreApplication::translate("Switch", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Switch", "<-\350\277\224\345\233\236", nullptr));
        label->setText(QCoreApplication::translate("Switch", "\350\276\223\345\205\245\345\207\217\344\273\223\351\207\221\351\242\235\357\277\245", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Switch", "\347\241\256\345\256\232", nullptr));
        label_4->setText(QCoreApplication::translate("Switch", "\351\200\211\346\213\251\350\246\201\350\275\254\345\205\245\347\232\204\350\202\241\347\245\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Switch: public Ui_Switch {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SWITCH_H
