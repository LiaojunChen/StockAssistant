#include "purchase.h"
#include "core.h"
#include "ui_purchase.h"
#include "getstock.h"
#include "SQLstock.h"
#include<QStringList>
Purchase::Purchase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Purchase)
{
    ui->setupUi(this);
}

Purchase::~Purchase()
{
    delete ui;
}

void Purchase::on_pushButton_clicked()
{
    this->close();
    Core* pc=new Core;
    pc->show();
}
//购买操作
void Purchase::on_pushButton_2_clicked()//购买股票
{
    QString stocknumber=ui->stocknumberinput_2->text();
    QString web="https://www.laohu8.com/stock/"+stocknumber;//输入股票代码
    QByteArray data;
    Getstock* m=new Getstock;
    m->init();
    m->getHttpData(web,data);
    m->handleData(data);
    m->handleData2(data);
    m->handleData3(data);
    m->handleData4(data);
    instantstock.stockname[0]=m->matchedText;
    instantstock.stocknumber[0]=stocknumber;
    instantstock.initprice[0]=m->urlList[0].toDouble();
    instantstock.currentprice[0]=m->urlList[0].toDouble();
    instantstock.positionamount[0]=ui->stockamountinput->text().toInt();
    instantstock.profitandloss[0]="0";
    instantstock.profitandlossrate[0]="0";
    instantstock.step[0]="购买";
    insertStockData(instantstock.stockname[0], instantstock.stocknumber[0], instantstock.initprice[0], instantstock.currentprice[0],instantstock.positionamount[0]);
    updatestocknamelist();
    updatestockinfo();
    this->close();
    Core* newcore=new Core;
    newcore->Core::showstock();
    Confirmation* pt=new Confirmation;
    pt->show();
}
