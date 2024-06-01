#include "options.h"
#include"SQLstock.h"
#include "getstock.h"
#include "ui_options.h"
#include <QApplication>
#include <QWidget>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QDebug>
Options::Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
        ui->comboBoxstockname->clear();
    int i=0;
    while(i<allstockname.size())
    {
        ui->comboBoxstockname->addItem(allstockname[i]);
        i++;
    }
}


Options::~Options()
{
    delete ui;
}
void Options::switchstock()
{
    connect(ui->comboBoxstockname,SIGNAL(currentTextChanged(QString)),this,SLOT(SetValue(QString)));
    instantstock.stockname[0]=ui->comboBoxstockname->currentText();
}
void Options::on_pushButton_clicked()
{
    this->close();
    Core* pc=new Core;
    pc->show();
}

void Options::on_plus_clicked()
{
    instantstock.stockname[0] = ui->comboBoxstockname->currentText();
    this->close();
    Plus* pp=new Plus;
    pp->show();
}

void Options::on_minus_clicked()
{
    instantstock.stockname[0] = ui->comboBoxstockname->currentText();
    this->close();
    Minus* pm=new Minus;
    pm->show();
}
//研究一下combo box怎么加入已有股票
