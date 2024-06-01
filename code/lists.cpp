#include "lists.h"
#include "ui_lists.h"
#include "getstock.h"

#include"SQLstock.h"
Lists::Lists(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lists)
{
    QStringList m={"美股","港股","伦敦","新加坡"};
    QStringList m2={"美股行情","港股行情","伦敦行情","基金行情"};
    ui->setupUi(this);
    if (ui->comboBox->count() > 1)
    {
        ui->comboBox->clear();
    }
    ui->comboBox->addItems(m);
    ui->comboBox_2->addItems(m2);
    showstockpic();
    Lists::showstock();
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged(int)));
    connect(ui->comboBox_2, SIGNAL(currentIndexChanged(int)), this, SLOT(onComboBoxChanged(int)));
}

Lists::~Lists()
{
    delete ui;
}
//切换到core页面
void Lists::on_switch_2_clicked()
{
    this->close();
    Core* newcore=new Core;
    newcore->Core::showstock();
    newcore->show();
}
//将持仓输出到ui
void Lists::showstock()
{
    ui->stockname->clear();
    ui->profitandloss->clear();
    ui->latestprofitandloss->clear();
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");
       if (!db.isOpen()) {
           qDebug() << "Error: failed to connect to the database." << db.lastError().text();
           return;
       }
       QSqlQuery query("SELECT * FROM stocks");
       QString result;
       while (query.next()) {
           QString stockname = query.value("stockname").toString();
           QString profitandloss = query.value("profitandloss").toString();
           QString latestprofitandloss =query.value("latestprofitandloss").toString();
           QString c1="red",c2="red";
           if(profitandloss[0]=='-')
           {
                c1="green";
           }
           if(latestprofitandloss[0]=='-')
           {
                c2="green";
           }
           QString content = QString("<span style='font-size:35px;color:%2;'>%1</span>")
                             .arg(stockname)
                             .arg(c1);
           ui->stockname->append(content);
           content = QString("<span style='font-size:35px;color:%2;'>%1</span>")
                             .arg(profitandloss)
                             .arg(c1);
           ui->profitandloss->append(content);
           content = QString("<span style='font-size:35px;color:%2;'>%1</span>")
                             .arg(latestprofitandloss)
                             .arg(c2);
           ui->latestprofitandloss->append(content);
       }
       //ui->stockoutput->append(result);
       qDebug()<<"showover"<<result;
   }
//combobox相关
void Lists::onComboBoxChanged(int index)
{
    showstockpic();
}
//展示股票信息pic
void Lists::showstockpic()
{
    QString load=ui->comboBox->currentText();
    QPixmap pixmap("C:/Users/Watson/Pictures/stockimg/"+load+".png");
    ui->stockpic->setFixedSize(pixmap.width()+60, pixmap.height()+40);
    ui->stockpic->setPixmap(pixmap);
    ui->stockpic->move(70, 170);
    ui->stockpic->show();
    QString load2=ui->comboBox_2->currentText();
    QPixmap pixmap2("C:/Users/Watson/Pictures/stockimg/"+load2+".png");
    ui->stockinfo->setFixedSize(pixmap2.width()+60, pixmap2.height());
    ui->stockinfo->setPixmap(pixmap2);
    ui->stockinfo->move(70, 690);
    ui->stockinfo->show();
}

