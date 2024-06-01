#include "search.h"
#include "ui_search.h"
#include "getstock.h"
#include"SQLstock.h"
Search::Search(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);

}
QString externtext="False";
int searchstate=0;
Search::~Search()
{
    delete ui;
}

void Search::on_pushButton_clicked()
{
    this->close();
    Core* pc=new Core;
    pc->show();
}
//搜索操作
void Search::on_pushButton_3_clicked()
{
    QString stocknumber=ui->stocknumberinput->text();
    instantstock.stocknumber[0]=stocknumber;
    QString web="https://www.laohu8.com/stock/"+stocknumber;//输入股票代码
    QByteArray data;
    Getstock* m=new Getstock;
    m->init();
    m->getHttpData(web,data);
    m->handleData4(data);
    ui->stocknameoutput->append(m->matchedText);
    if(searchstate==0)
    {
    m->handleData(data);
    ui->stockpriceoutput->append(m->urlList[0]);
    m->handleData2(data);
    ui->stockrateoutput->append(m->urlList2[0]);
    m->handleData3(data);
    ui->stockrateoutput->append("/"+m->urlList3[0]);
    }
    externtext="True";
}

void Search::on_pushButton_2_clicked()
{

    this->close();
    Purchase* pp=new Purchase;
    pp->show();
}
