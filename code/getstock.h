#ifndef GETSTOCK_H
#define GETSTOCK_H
#include "ui_dialog.h"
#include <QDialog>
#include<qnetworkaccessmanager.h>
#include<QNetworkReply>
#include <QNetworkRequest>
#include <QTextEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE
void webgetlateststock(const QString& n);
struct myStock{
    QStringList stockname;
    QStringList stocknumber;
    QList<double> initprice;
    QList<double> currentprice;
    QList<double> cost;
    QList<int> positionamount;
    QStringList profitandloss;
    QStringList profitandlossrate;
    QStringList step;
    QStringList latestprofitandloss;
};
extern myStock instantstock;
extern myStock userstock;
extern QSettings* mystock;
extern QStringList allstockname;
void initextern();
class Getstock : public QWidget
{
    Q_OBJECT

public:
    Getstock(QWidget *parent = nullptr);
    ~Getstock();

public:
    QString matchedText;
    QNetworkAccessManager *manager;
    QStringList urlList;
    QStringList urlList2;
    QStringList urlList3;
    QStringList urlList4;
public:
    void init(); //初始化函数
    void getHttpData(const QString&modelUrl,QByteArray & data); //获取网页数据
    void handleData(QByteArray & data);
    void handleData2(QByteArray &data);
    void handleData3(QByteArray &data);
    void handleData4(QByteArray &data);
    void saveImg();
    void savestock();
    void initializemystock();
   ///void sendChatGPTRequest(QString message);
    //void sendRequest();
    void handleReply(QNetworkReply *reply);
private slots:
    //void on_Analysis_Btn_clicked();
    //void on_pushButton_clicked();
    //void on_find_clicked();
};
#endif // GETSTOCK_H
