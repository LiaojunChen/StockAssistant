#include"Screenshotter.h"
#include"ui_Screenshotter.h"
#include <QApplication>
#include <QScreen>
#include <QApplication>
#include <QScreen>
#include <QTimer>
//#include <QWebView>
#include <QDebug>
#include<QUrl>
#include<qdebug.h>
#include <QString>
#include<qdebug.h>
//#include <QtWebKitWidgets/QWebView>

Screenshotter::Screenshotter(QWidget *parent)
    : QWidget(parent)

{
    //view=new QWebView(this);
    /*
    ui->setupUi(this);


    ui->verticalLayout_2->addWidget(view);*/
}
Screenshotter::~Screenshotter()
{

}

/*
void viewclicktest()
{
    QWebView *view=new QWebView;
     view->load(QUrl("https://www.laohu8.com/quotes?quotesMarket=US"));
}*/


