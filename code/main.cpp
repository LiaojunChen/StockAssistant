#include "dialog.h"
#include"core.h"
#include <QApplication>
#include"SQLstock.h"
#include "getstock.h"
#include"Screenshotter.h"
#include "WebPageScreenshot.h"
#include "get_url_pix.h"
#include <QDateTime>
int main(int argc, char *argv[])
{
    //进行各种信息初始化
    //获取最新持仓信息，更新收益，初始化股市行情，等等初始化

    QSettings settings("MyCompany", "MyApp");
    QTime currentTime = QTime::currentTime();
    QString currenttime=currentTime.toString();
    QString time=settings.value("time", currenttime).toString();
    settings.setValue("time", currenttime);
    searchstate=0;

    QApplication a(argc, argv);
    Dialog w;
    //deleteStockByNumber("英伟达");
    initializeDatabase();
    initextern();
    updatestockinfo();
    updatestocknamelist();
    qDebug() <<"初始化完成";


    Core* nc=new Core;
    /*if(time[3]!=currenttime[3])
    {
    get_url_pix* pix=new get_url_pix;
    pix->on_url_down_clicked();
    }*/

    qDebug()<<"保存成功";
    qDebug() <<allstockname;
    nc->updatefiancenews();
    nc->getanalysis();
    w.show();
    return a.exec();
}
//WebPageScreenshot screenshot;
//screenshot.capture("https://www.qt.io", "screenshot.png");
//Screenshotter screenshotter("https://www.laohu8.com/quotes?quotesMarket=US", QRect(100, 100, 400, 300), "screenshot.png");
