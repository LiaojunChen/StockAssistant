#include "confirmation.h"
#include "ui_confirmation.h"
#include "getstock.h"
#include"SQLstock.h"
#include <QMessageBox>
Confirmation::Confirmation(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Confirmation)
{
    ui->setupUi(this);
    if(instantstock.step[0]=="清仓")
    {
        QString m="清仓"+instantstock.stockname[0]+"(股价"+QString::number(instantstock.currentprice[0], 'f', 2)+")";
        QString n=QString("<span style='font-size:35px;color:black;'>%1</span>")
                                     .arg(m);
        ui->confirmation->append(n);
        return;
}
    int state=0;
    QString m=instantstock.step[0]+instantstock.stockname[0]+"(股价"+QString::number(instantstock.currentprice[0], 'f', 2)+")"+" "+QString::number(abs(instantstock.positionamount[0]))+"股";
    qDebug()<<"输出确认"<<m;

    QString n=QString("<span style='font-size:35px;color:black;'>%1</span>")
                                 .arg(m);
    ui->confirmation->append(n);

}

Confirmation::~Confirmation()
{
    delete ui;
}
//跳转选项
void Confirmation::on_pushButton_clicked()
{


    this->close();
    Options* fa=new Options;
    fa->show();
}
//跳转回去
void Confirmation::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("操作成功");
    msgBox.exec();
    this->close();
    Core* pt=new Core;
    pt->show();
}
