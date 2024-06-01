#include "dialog.h"
#include "ui_dialog.h"
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
#include"SQLstock.h"
#include "getstock.h"
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
#include"Screenshotter.h"
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

#include <QJsonObject>
#include <QJsonDocument>
#include"core.h"
#include "getstock.h"
#include"SQLstock.h"
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    init();
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    qDebug() << manager->supportedSchemes();
}

void Dialog::init()
{
    manager = new QNetworkAccessManager(this);

}

void Dialog::on_pushButton_clicked()
{
   this->close();
   llmmodel="FinAssistant";
   Lists* pl=new Lists;
   pl->Lists::showstock();
   pl->show();
}
Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_2_clicked()
{
    this->close();
    llmmodel="GPT-4o";
    Lists* pl=new Lists;
    pl->Lists::showstock();
    pl->show();
}
