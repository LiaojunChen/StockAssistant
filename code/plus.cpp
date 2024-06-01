#include "plus.h"
#include "ui_plus.h"
#include "getstock.h"
#include"SQLstock.h"
Plus::Plus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Plus)
{
    ui->setupUi(this);
}

Plus::~Plus()
{
    delete ui;
}

void Plus::on_pushButton_clicked()
{
    this->close();
    Options* fa=new Options;
    fa->show();
}
//增仓操作
void Plus::on_pushButton_2_clicked()
{
    instantstock.positionamount[0]=ui->stockamountinput->text().toInt();
    updatepositionamount(instantstock.stockname[0],instantstock.positionamount[0]);
    instantstock.step[0]="增持";
    this->close();
    Confirmation* pc=new Confirmation;
    pc->show();
}
