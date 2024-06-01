#include "zsmtp.h"
#include <QDebug>

ZSmtp::ZSmtp(QString serverIP, QObject *parent) : QObject(parent)
{
    this->serverIP = serverIP;
    tcpSocket = new QTcpSocket;
    connect(tcpSocket, SIGNAL(connected()), this, SLOT(connectToServer()));
    connect(tcpSocket, SIGNAL(disconnected()), this, SLOT(disconnectFromServer()));
    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(getMessage()));
    qDebug()<<"ZSmtp";
}

ZSmtp::~ZSmtp()
{
    delete tcpSocket;
    qDebug()<<"~ZSmtp";
}

void ZSmtp::sendEmail(QString username, QString password, QString to, QString title, QString text, QString ip)
{
    if(ip != "")
    {
        serverIP = ip;
    }
    this->username = username;
    this->password = password;
    this->to = to;
    this->title = title;
    this->text = text;
    tcpSocket->abort();
    serverText.clear();
    status = 0;
    tcpSocket->connectToHost(serverIP, 25);
}

void ZSmtp::connectToServer()
{
    qDebug()<<"connect to server";
}

void ZSmtp::disconnectFromServer()
{
    qDebug()<<"disconnect from server";
    emit disconnected();
}

#define STATUS_MAX 6
void ZSmtp::getMessage()
{
    QByteArray curText = tcpSocket->readAll();
    serverText.append(curText);
    QByteArray text;
    //qDebug()<<curText;
    if(serverText.indexOf("Error")!=-1 || serverText.indexOf("503")!=-1)
    {
        //出错了
        qDebug()<<"get the Error message";
        emit emailStatus(EMAIL_ERROR);
        tcpSocket->disconnectFromHost();
        return ;
    }
    if(status==5 && serverText.indexOf("250")!=-1)
    {
        //登出
        text.append("QUIT\r\n");
        status = 6;
    }
    else if(status==4 && serverText.indexOf("354")!=-1)
    {
        //发信息
        text.append("Subject:=?utf-8?B?");
        text.append(QByteArray().append(title).toBase64());
        text.append("?=\r\n");
        text.append("To: ");
        text.append(to);
        text.append("\r\nFrom: ");
        text.append(username);
        text.append(" <");
        text.append(username);
        text.append(">\r\n");
        text.append("Content-Type: text/plain; charset=UTF8;\r\n");
        text.append("Content-Transfer-Encoding: 7BIT\r\n\r\n");
        QString t = this->text;
        t.replace("\n", "\r\n").replace("\r\n.\r\n", "\r\n..\r\n");
        text.append(t);
        text.append("\r\n.\r\n");
        status = 5;
    }
    else if(status==3 && serverText.indexOf("250")!=-1)
    {
        //DATA
        text.append("DATA\r\n");
        status = 4;
    }
    else if(status==2 && serverText.indexOf("235")!=-1)
    {
        //发送方和接收方
        text.append("MAIL FROM: <");
        text.append(username);
        text.append(">\r\n");
        text.append("RCPT TO: <");
        text.append(to);
        text.append(">\r\n");
        status = 3;
    }
    else if(status==1 && serverText.indexOf("334")!=-1)
    {
        //登录
        text.append(QByteArray().append(username).toBase64());
        text.append("\r\n");
        text.append(QByteArray().append(password).toBase64());
        text.append("\r\n");
        status = 2;
    }
    else if(status==0 && serverText.indexOf("220")!=-1)
    {
        //打招呼
        text.append("EHLO ");
        text.append(serverIP);
        text.append("\r\nAUTH LOGIN\r\n");
        status = 1;
    }
    tcpSocket->write(text);
    //qDebug()<<text;
    emit progress((double)status/STATUS_MAX);   //进度
    if(status == 6)
    {
        emit emailStatus(EMAIL_SUCCEED);
        tcpSocket->disconnectFromHost();
    }
}

void ZSmtp::sendEmailSlot(QString username, QString password, QString to, QString title, QString text)
{
    sendEmail(username, password, to, title, text);
}
