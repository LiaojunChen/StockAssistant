#include "getstock.h"
#include "ui_core.h"

#include <QSettings>
#include<QString>
#include<QStringList>
#include<qbytearray.h>
#include<QUrl>
#include<qdebug.h>
#include<qmessagebox.h>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QString>
#include <QDebug>
#include<qdebug.h>
#include <QDebug>

#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QNetworkReply>
#include <QJsonArray>
#include <QJsonObject>
#include<QString>
#include<qbytearray.h>
#include<QUrl>
#include<qdebug.h>
#include<qmessagebox.h>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QString>
#include <QDebug>
#include<qdebug.h>
#include<QString>
#include<qbytearray.h>
#include<QUrl>
#include<qdebug.h>
#include<qmessagebox.h>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QString>
#include <QDebug>
#include<qdebug.h>
#include <QDebug>

#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

#include <QJsonObject>
#include <QJsonDocument>

#include <QString>
#include <QRegExp>
#include <QDebug>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include"SQLstock.h"
#include "getstock.h"
#include <QMessageBox>
Getstock::Getstock(QWidget *parent)
    : QWidget(parent)
{

    init();
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    //qDebug() << manager->supportedSchemes();   //http故障时使用
}
Getstock::~Getstock()
{

}
QStringList allstockname;
myStock instantstock;
myStock userstock;
QSettings* mystock=nullptr;

//初始化所有全局变量
void initextern()
{
    allstockname.append("0");
    instantstock.stockname.append("0");
        instantstock.stocknumber.append("0");
        instantstock.initprice.append(0.00);
        instantstock.currentprice.append(1.00);
        instantstock.cost.append(0.00);
        instantstock.positionamount.append(0);
        instantstock.profitandloss.append("0");
        instantstock.profitandlossrate.append("0");
        instantstock.step.append("0");
        instantstock.latestprofitandloss.append("0");
}
//初始化networkaccessmanager
void Getstock::init()
{
    manager = new QNetworkAccessManager(this);
}

//获取网页源代码，转化为字节
void Getstock::getHttpData(const QString&modelUrl,QByteArray&data)//获取网页信息
{
    QUrl url(modelUrl);
    QNetworkRequest request;
    request.setUrl(url);
    QNetworkReply * reply_ = manager->get(request);
    QEventLoop eventLoop2;
    connect(reply_, &QNetworkReply::finished, &eventLoop2, &QEventLoop::quit);
    eventLoop2.exec(QEventLoop::ExcludeUserInputEvents);
    data = reply_->readAll();

    reply_->deleteLater();
}

//预处理股价
void Getstock::handleData(QByteArray &data)//处理股价
{
        QString str = QString(data);

       QRegExp exp("<span class=\"stock-price (?:increase|decrease)\">\\s*(\\d+\\.\\d+)\\s*</span>");
        //exp.setMinimal(false);
        QStringList list = str.split("\n");
        urlList.clear();
        for (int i = 0;i < list.size();++i)
        {
            int pos = 0;
            while ((pos = exp.indexIn(list.at(i) , pos)) != -1)
            {
                pos += exp.matchedLength();
                urlList << exp.cap(0);
            }
        }
        QRegExp numExp("[\\d]+\\.\\d+");  // 创建用于匹配浮点数的正则表达式
        QStringList numberList;         // 创建一个列表存储提取的数字
        foreach (const QString &entry, urlList) {
            int pos = 0;
            while ((pos = numExp.indexIn(entry, pos)) != -1) {
                QString number = numExp.cap(0);  // 捕获匹配到的浮点数
                numberList.append(number);       // 将浮点数添加到列表中
                pos += numExp.matchedLength();   // 移动到下一个可能的匹配位置
            }

            urlList[0]=numberList[0];
        }
}
//预处理涨跌
void Getstock::handleData2(QByteArray &data)//处理涨跌
{
        QString str = QString(data);
        QRegExp exp("<span class=\"stock-change \\w+\">([+-]?\\d+\\.\\d+)</span>");
        //exp.setMinimal(false);
        QStringList list = str.split("\n");
        urlList2.clear();
        for (int i = 0;i < list.size();++i)
        {
            int pos = 0;
            while ((pos = exp.indexIn(list.at(i) , pos)) != -1)
            {
                pos += exp.matchedLength();
                urlList2 << exp.cap(0);
            }
        }
        QRegExp numExp("[+-]?\\d+\\.\\d+");
        QStringList numberList;
        foreach (const QString &entry, urlList2) {
            int pos = 0;
            while ((pos = numExp.indexIn(entry, pos)) != -1) {
                QString number = numExp.cap(0);
                numberList.append(number);
                pos += numExp.matchedLength();
            }
            urlList2[0]=numberList[0];

        }

}
//预处理涨跌百分比
void Getstock::handleData3(QByteArray &data)//处理涨跌百分比
{
        QString str = QString(data);
       QRegExp exp("<span class=\"stock-change-rate \\w+\">([+-]?\\d+\\.\\d+%?)</span>");
        //exp.setMinimal(false);
        QStringList list = str.split("\n");
        urlList3.clear();
        for (int i = 0;i < list.size();++i)
        {
            int pos = 0;
            while ((pos = exp.indexIn(list.at(i) , pos)) != -1)
            {
                pos += exp.matchedLength();
                urlList3 << exp.cap(0);
            }
        }
        QRegExp numExp("[+-]?\\d+\\.\\d+%?");
        QStringList numberList;
        foreach (const QString &entry, urlList3) {
            int pos = 0;
            while ((pos = numExp.indexIn(entry, pos)) != -1) {
                QString number = numExp.cap(0);
                numberList.append(number);
                pos += numExp.matchedLength();
            }
            urlList3[0]=numberList[0];

        }
}
//预处理股票名称
void Getstock::handleData4(QByteArray &data)//处理股票名称
{
    QString str = QString(data);
   QRegExp exp("<h2 class=\"basic-stock-name\">(.*?)<!-- -->");
   exp.setMinimal(true);
    QStringList list = str.split("\n");

    urlList4.clear();
    QRegularExpression re("<h2 class=\"basic-stock-name\">(.*?)<!-- -->");
        QRegularExpressionMatch match = re.match(str);
        if (match.hasMatch()) {
            matchedText = match.captured(1);  // 获取第一个捕获组的匹配内容
            qDebug() << "Extracted Text:" << matchedText;
        } else {
            qDebug() << "No match found";
            QMessageBox::critical(nullptr, "错误", "请输入正确的股票代码");
            searchstate=1;
        }
}
//整合上述函数，一次性获得所有股票信息
void webgetlateststock(const QString& n)
{
    QString stocknumber=n;
    QString web="https://www.laohu8.com/stock/"+stocknumber;//输入股票代码
    QByteArray data;
    Getstock* m=new Getstock;
    m->init();
    m->getHttpData(web,data);
    m->handleData(data);
    if(!instantstock.currentprice.isEmpty() && !m->urlList.isEmpty())

    instantstock.currentprice[0]=m->urlList[0].toDouble();
    else
        qDebug()<<"有一个empt'y";
    m->handleData2(data);
    m->handleData3(data);
    if(instantstock.latestprofitandloss.isEmpty())
    {
        qDebug()<<"lplempty";
    }
    else
    {
        qDebug()<<"ok";
    instantstock.latestprofitandloss[0]=m->urlList3[0];
    }
}


