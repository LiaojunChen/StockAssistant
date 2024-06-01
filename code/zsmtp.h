#ifndef ZSMTP_H
#define ZSMTP_H

#include <QObject>
#include <QTcpSocket>

#define EMAIL_ERROR     0   //邮件发送失败
#define EMAIL_SUCCEED   1   //邮件发送成功

class ZSmtp : public QObject
{
    Q_OBJECT
public:
    explicit ZSmtp(QString serverIP = "smtp.qq.com", QObject *parent = NULL);
    ~ZSmtp();
    void sendEmail(QString username, QString password, QString to, QString title, QString text, QString ip = "");

private:
    QString serverIP;
    QTcpSocket *tcpSocket;
    QString username;
    QString password;
    QString to;
    QString title;
    QString text;
    QByteArray serverText;
    int status;

signals:
    void disconnected();
    void emailStatus(int status);   //邮件发送的状态
    void progress(double p);

public slots:
    void connectToServer();
    void disconnectFromServer();
    void getMessage();

    void sendEmailSlot(QString username, QString password, QString to, QString title, QString text);

};

#endif // ZSMTP_H
