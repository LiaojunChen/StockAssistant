#include "get_url_pix.h"
#include <QDebug>
#include <QEventLoop>
#include <QCoreApplication>
#include <QPixmap>
#include <QDebug>
#include<QJsonDocument>
#include<QJsonObject>
#include <QUrlQuery>
get_url_pix::get_url_pix(QWidget *parent) :
    QWidget(parent)
{

}

get_url_pix::~get_url_pix()
{

}
//调用api，获取目标图片的url地址
void get_url_pix::getScreenshoturl(const QString &name) {
    QUrl apiUrl("https://shot.screenshotapi.net/screenshot");
    QUrlQuery query;
    QString url="https://www.laohu8.com/quotes?quotesMarket=";
    query.addQueryItem("token", "7S2WJFX-XY4M4DG-GDTAQE0-FATM0PV");
    query.addQueryItem("url", url+name);
    query.addQueryItem("full_page", "true");
    query.addQueryItem("output", "json");
    query.addQueryItem("file_type", "png");
    apiUrl.setQuery(query);
    QNetworkRequest request(apiUrl);
    QNetworkAccessManager manager;
    QNetworkReply * reply = manager.get(request);
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray responseData = reply->readAll();
        QJsonDocument doc = QJsonDocument::fromJson(responseData);
        QJsonObject jsonObj = doc.object();
        QString screenshotUrl = jsonObj["screenshot"].toString();
        imgurl=screenshotUrl;
        }
     else {
        qDebug() << "Error:" << reply->errorString();
    }
    reply->deleteLater();

}

//得到地址后，访问地址获取图片
bool downIURL_to_picture(const QString &url, const QString &fileName)
{
    //构造请求
    QNetworkAccessManager manager;
    QNetworkRequest request;
    request.setUrl(url);
    // 发送请求
    QNetworkReply *reply = manager.get(request);
    //开启一个局部的事件循环，等待响应结束，退出
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
    //判断是否出错
    if (reply->error() != QNetworkReply::NoError)
    {
        return false;
    }
    //SAVE FILE
    QFile f(fileName);
    if(!f.open(QIODevice::WriteOnly))
        return false;
    f.write(reply->readAll());
    f.close();
    delete reply;
    return true;
 }

//利用上述两个函数，获取需要的信息
void get_url_pix::on_url_down_clicked()
{
    QString weburl="https://www.laohu8.com/quotes?quotesMarket=";

    QStringList name={"美股","港股","伦敦","新加坡","美股行情","港股行情","伦敦行情","基金行情"};
    QStringList url_name={"US","HK","UK","SI","SI&boardMarket=US","SI&boardMarket=HK","SI&boardMarket=UK","SI&boardMarket=FUND"};
    for(int i=0;i<8;i++)
    {
    QString fileName = "C:/Users/Watson/Pictures/stockimg/" + name[i] + ".png";//指定文件夹路径
    //qDebug() << "file:" << fileName << endl;
    //qDebug() << "name:" << url_name << endl;
    getScreenshoturl(url_name[i]);
     downIURL_to_picture(imgurl,fileName);
    // 1. 加载图片
    QPixmap originalPixmap("C:/Users/Watson/Pictures/stockimg/"+name[i] + ".png"); // 替换为你的图片路径
    if (originalPixmap.isNull()) {
        qDebug() << "图片加载失败！请检查路径是否正确。";
        return ;
    }
    // 2. 定义截图区域
    QPixmap croppedPixmap;

    if(i<4)
    {
    QRect cropArea(250, 80, 840, 440);
    croppedPixmap = originalPixmap.copy(cropArea);

    }
    else
    {
     QRect cropArea(250, 950, 840, 440);
     croppedPixmap = originalPixmap.copy(cropArea);
    }
    // 3. 保存截取的图片
    bool result = croppedPixmap.save("C:/Users/Watson/Pictures/stockimg/"+name[i] + ".png"); // 替换为你想保存的路径

    if (!result) {
        qDebug() << "图片保存失败！";
        return ;
    }
    qDebug() << "图片成功保存。";
}
    return ;
}



