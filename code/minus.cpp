#include "minus.h"
#include "ui_minus.h"
#include"SQLstock.h"
#include "getstock.h"
Minus::Minus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Minus)
{
    ui->setupUi(this);
}

Minus::~Minus()
{
    delete ui;
}

void Minus::on_pushButton_clicked()
{
    this->close();
    Options* fa=new Options;
    fa->show();
}
//减持操作
void Minus::on_pushButton_2_clicked()
{
    instantstock.positionamount[0]=abs(ui->stockamountinput->text().toInt())*(-1);
    updatepositionamount(instantstock.stockname[0],instantstock.positionamount[0]);
    instantstock.step[0]="减持";
    updatestocknamelist();
    this->close();
    if(state==0)
    {
    Confirmation* pc=new Confirmation;
    pc->show();
    }
    else
    {
        Core* c=new Core;
        c->show();
    }
}
//清仓操作
void Minus::on_minusall_clicked()
{
    instantstock.positionamount[0]=0;
    updatepositionamount(instantstock.stockname[0],instantstock.positionamount[0]);
    instantstock.step[0]="清仓";
    updatestocknamelist();
    this->close();
    Confirmation* pc=new Confirmation;
    pc->show();
}
