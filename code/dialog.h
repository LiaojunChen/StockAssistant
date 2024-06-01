#ifndef DIALOG_H
#define DIALOG_H

#include "ui_dialog.h"
#include <QDialog>
#include<qnetworkaccessmanager.h>
#include<QNetworkReply>
#include <QNetworkRequest>
#include <QTextEdit>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include<lists.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE





class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    QNetworkAccessManager *manager;
    QStringList urlList;
    QStringList urlList2;
    QStringList urlList3;
private:

    void init(); //初始化函数
    void getHttpData(const QString&modelUrl,QByteArray & data); //获取网页数据
    void handleData(QByteArray & data);
    void handleData2(QByteArray &data);
    void handleData3(QByteArray &data);
    void saveImg();
   ///void sendChatGPTRequest(QString message);
    //void sendRequest();
    void handleReply(QNetworkReply *reply);
    void extractNumbers(QStringList &urlList);
    void extractdecreaseNumbers(QStringList &urlList);
    void extractrateNumbers(QStringList &urlList);
private slots:
    //void on_Analysis_Btn_clicked();
    void on_pushButton_clicked();
    //void on_find_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
