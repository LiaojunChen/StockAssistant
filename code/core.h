#ifndef CORE_H
#define CORE_H

#include <QWidget>
#include<lists.h>
#include<options.h>
#include<search.h>
#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>


extern QString llmmodel;
extern QString content;
namespace Ui {
class Core;
}
extern QString chatgptresponse;
extern QString everydaynews;

class Core : public QWidget
{
    Q_OBJECT

public:

    QString FinPrompt;
    explicit Core(QWidget *parent = nullptr);
    ~Core();
    void showstock();
    void getthreadandrunid();
    void createthreadandrun(QString& input);
    void getrunstatus();
    void checkrunstatus();
    void getstepidrequest();
    void getmessageid();
    void sendgetmessagerequest();
    void getmessage();
    void getanalysis();
    void chatwithGPT(QString &input,QString model);
    void on_responseReceived(QNetworkReply *reply);
    void on_readyRead();
    void on_finished();
    void circletoget();
    QString chatResponse;
    int requeststate=0;
    int getstate=0;
    int statec=0;

    QNetworkAccessManager *networkManager;
    QNetworkAccessManager *fanetworkManager;
    QNetworkReply *runthreadreply;
    QNetworkReply *getrunreply;
    QNetworkReply *getstepreply;
    QNetworkReply *getmessagereply;
        QNetworkReply *currentreply;
        QString openaiApiKey;
        QString currentResponse;
    void updatefiancenews();
    void sendRequest(QString& input);
    QString run_id;
    QString thread_id;
    QString status="0";
    QString message_id;
    QString message;


private slots:
    void on_Switch_Mode_Button_clicked();


    void on_Switch_Mode_Button_2_clicked();

    void on_pushButton_3_clicked();

    void on_switchbutton_2_clicked();

    void on_GPTbutton_clicked();
    void on_emailsendinfo_clicked();

    void on_emailsendnews_clicked();

    void on_commendbutton_clicked();

public:
    Ui::Core *ui;
};


#endif // CORE_H
