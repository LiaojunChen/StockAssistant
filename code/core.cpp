#include "core.h"
#include "ui_core.h"

#include "getstock.h"
#include "options.h"
#include"SQLstock.h"
#include"zsmtp.h"
#include <QApplication>
#include <QWidget>
#include <QComboBox>
#include <QSqlQueryModel>
#include <QVBoxLayout>
#include <QSqlDatabase>
#include <QDebug>
#include "ChatDialog.h"
#include "ui_core.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include"core.h"
Core::Core(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Core)
{
    ui->setupUi(this);
    networkManager = new QNetworkAccessManager(this);
    fanetworkManager = new QNetworkAccessManager(this);
    openaiApiKey="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";
    connect(networkManager, &QNetworkAccessManager::finished, this, &Core::on_responseReceived);
    Core::showstock();
    ui->finnewsoutput->append(everydaynews);
    ui->chatoutput->append(content);
    if(externtext=="True")
    {
        QString searchprompt="结合给你提供的file内容以及你模型本身具有的知识，介绍一下股票代码为"+instantstock.stocknumber[0]+"的股票，如果给定的文件中没有相关信息，则结合你模型自身的知识进行介绍，不得不进行介绍";
        chatwithGPT(searchprompt,"FinAssistant");
        statec=1;
        externtext="False";
    }
}
QString content="请输入prompt";
QString llmmodel;
QString searchprompt;
QString prompt="";
QString everydaynews=QString("<span style='font-size:35px;'>%1</span>")
        .arg("正在准备财经新闻……");
Core::~Core()
{
    delete ui;
}
void Core::getanalysis()
{
    GetStockData();
    FinPrompt="现在我会给你提供我的持仓信息，你需要针对我的持仓给出针对性建议，包括持仓情况分析，改变持仓的建议";
    if(userstock.stockname.size()<1)
    {
        int m=userstock.stockname.size();
        qDebug()<<"userstock错误"<<m;
    }
    else
    {
    for(int i=0;i<userstock.stockname.size();i++)
    {
        FinPrompt+="股票名称："+userstock.stockname[i]+' ';
        FinPrompt+="股票原始价："+QString::number(userstock.initprice[i], 'f', 2)+' ';
        FinPrompt+="股票现价："+QString::number(userstock.currentprice[i],'f',2)+' ';
        FinPrompt+="持仓总额："+QString::number(userstock.positionamount[i]*userstock.currentprice[i],'f',2)+' ';
        FinPrompt+="累计收益："+userstock.profitandloss[i]+' ';
        FinPrompt+="累计收益率："+userstock.profitandlossrate[i]+' ';
        FinPrompt+="股票最新涨跌："+userstock.latestprofitandloss[i]+' ';
    }
    chatwithGPT(FinPrompt,"FinAssistant");
    }
}



//将stock展示到ui
void Core::showstock()
{
    ui->stockname->clear();
    ui->positionamount->clear();
    ui->stockprice->clear();
    ui->profitandlossrate->clear();
    ui->latestprofitandloss->clear();
    QSqlDatabase db = QSqlDatabase::database("qt_sql_default_connection");
       if (!db.isOpen()) {
           qDebug() << "Error: failed to connect to the database." << db.lastError().text();
           return;
       }
       QSqlQuery query("SELECT * FROM stocks");
       while (query.next()) {
           QString stockname = query.value("stockname").toString();
           QString stocknumber = query.value("stocknumber").toString();
           double initprice = query.value("initprice").toDouble();
           double currentprice = query.value("currentprice").toDouble();
           int positionamount = query.value("positionamount").toInt();
           QString profitandloss = query.value("profitandloss").toString();
           QString latestprofitandloss = query.value("latestprofitandloss").toString();
           QString profitandlossrate = query.value("profitandlossrate").toString();
           QString positionprice=QString::number(currentprice*positionamount,'f',2);
           QString c1="red",c2="red",c3="black";
           QString x=" ";
               if(profitandloss[0]=='-')
               {
                    c1="green";
               }
               if(latestprofitandloss[0]=='-')
               {
                    c2="green";
               }
               QString content="0";
               QString block=QString("<span style='display:inline-block; width:35px;'></span>");
               content= QString("<span style='font-size:35px;color:%2;'>%1</span><br>")
                       .arg(stockname)
                       .arg(c1);
               ui->stockname->append(content);
               ui->stockname->append(block);
               content= QString("<span style='font-size:35px;color:%2;'>%1</span>")
                       .arg(positionprice)
                       .arg(c3);
               ui->positionamount->append(content);
               content= QString("<span style='font-size:35px;color:%2;'>%1</span>")
                       .arg(currentprice)
                       .arg(c3);
               ui->stockprice->append(content);
               content= QString("<span style='font-size:35px;color:%2;'>%1</span><br>")
                       .arg(profitandlossrate)
                       .arg(c1);
               ui->profitandlossrate->append(content);
               ui->profitandlossrate->append(block);
               content= QString("<span style='font-size:35px;color:%2;'>%1</span><br>")
                       .arg(latestprofitandloss)
                       .arg(c2);
               ui->latestprofitandloss->append(content);
               ui->latestprofitandloss->append(block);
               content= QString("<span style='font-size:35px;color:%2;'>%1</span>")
                       .arg(profitandloss)
                       .arg(c1);
               ui->positionamount->append(content);
               content= QString("<span style='font-size:35px;color:%2;'>%1</span>")
                       .arg(initprice)
                       .arg(c3);
               ui->stockprice->append(content);
           }
   }
//切换到lists界面
void Core::on_Switch_Mode_Button_clicked()
{
    this->close();
    Lists* fa=new Lists;
    fa->show();
}

//切换到search界面
void Core::on_Switch_Mode_Button_2_clicked()
{
    this->close();
    Search* ps=new Search;
    ps->show();
}

//切换到购买界面
void Core::on_pushButton_3_clicked()
{
    this->close();
    Purchase* pp=new Purchase;
    pp->show();
}

//切换到选项界面
void Core::on_switchbutton_2_clicked()
{
    this->close();
    Options* po=new Options;
    po->show();
}

//发送消息与GPT交互
void Core::on_GPTbutton_clicked()
{
    statec=1;
    QString userInput = ui->chatinput->toPlainText();
    chatwithGPT(userInput,llmmodel);
}
void Core::chatwithGPT(QString &input,QString model)
{
    QString userInput = input;
    ui->chatoutput->append("开始输出……请稍后……");
    if(model=="GPT-4o")
    {
     requeststate=0;
     getstate=1;
     sendRequest(userInput);
    QString chatoutputtext=chatResponse;
    qDebug()<<"输出内容是"<<message;
    }

    else if(model=="FinAssistant")
    {
    requeststate=0;
    getstate=1;
    createthreadandrun(userInput);
    QString chatoutputtext=chatResponse;
    qDebug()<<"输出内容是"<<message;
    }
}

//创建thread和run 包含message发出
void Core::createthreadandrun(QString& input) {
        QString userInput = input;
        /*将'{
        "assistant_id": "asst_abc123",
        "thread": {
          "messages": [
            {"role": "user", "content": "Explain deep learning to a 5 year old."}
          ]
        }
      }'转化为json*/
        QJsonObject messageObject;
        messageObject["role"] = "user";
        messageObject["content"] = input;

        QJsonArray messagesArray;
        messagesArray.append(messageObject);

        QJsonObject threadObject;
        threadObject["messages"] = messagesArray;

        QJsonObject mainObject;
        mainObject["assistant_id"] = "asst_7xUQ2LEmRfBi8Qp4XcA0UzOA";
        mainObject["thread"] = threadObject;
        /*curl转化
         * curl https://api.openai.com/v1/threads/runs \
        -H "Authorization: Bearer $OPENAI_API_KEY" \
        -H "Content-Type: application/json" \
        -H "OpenAI-Beta: assistants=v2" \
        -d '{
      "assistant_id": "asst_abc123",
      "thread": {
        "messages": [
          {"role": "user", "content": "Explain deep learning to a 5 year old."}
        ]
      }
    }'*/
        if(getstate==1)
        {
        QNetworkRequest request(QUrl("https://api.openai.com/v1/threads/runs"));
        request.setRawHeader("OpenAI-Beta", "assistants=v2");
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Authorization", "Bearer " + openaiApiKey.toUtf8());
        runthreadreply = fanetworkManager->post(request, QJsonDocument(mainObject).toJson());
        qDebug()<<"create run and thread已发出";
        //QTimer::singleShot(30000, runthreadreply, &QNetworkReply::abort); // 30 seconds timeoutqDebug()<<"GPT输入成功";
        connect(runthreadreply, &QNetworkReply::finished, this, &Core::getthreadandrunid);
        requeststate=1;
        }
}
//获取runid和threadid
void Core::getthreadandrunid()
{
    if (runthreadreply->error() == QNetworkReply::NoError)
            {
                QByteArray response = runthreadreply->readAll();
                QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
                QJsonObject jsonObject = jsonResponse.object();
                run_id = jsonObject.value("id").toString();
                thread_id = jsonObject.value("thread_id").toString();
                qDebug()<<"已获取threadid and runid";
            }
            else
            {
                qDebug()<<"Error: " <<runthreadreply->errorString();
            }
    runthreadreply->deleteLater();
    getrunstatus();
}

//查询run状态
void Core::getrunstatus() {

        QNetworkRequest request(QUrl("https://api.openai.com/v1/threads/"+thread_id+"/runs/"+run_id));
        request.setRawHeader("OpenAI-Beta", "assistants=v2");
        request.setRawHeader("Authorization", "Bearer " + openaiApiKey.toUtf8());
        getrunreply = fanetworkManager->get(request);
        qDebug()<<"查询run状态已发出";

        //QTimer::singleShot(30000, getrunreply, &QNetworkReply::abort); // 30 seconds timeoutqDebug()<<"GPT输入成功";
        connect(getrunreply, &QNetworkReply::finished, this, &Core::checkrunstatus);
}
void Core::checkrunstatus()
{
    QString last_error;
    if (getrunreply->error() == QNetworkReply::NoError)
            {
                QByteArray response = getrunreply->readAll();
                QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
                QString jsonString = jsonResponse.toJson(QJsonDocument::Compact);
                QJsonObject jsonObject = jsonResponse.object();
                status = jsonObject.value("status").toString();
                 last_error= jsonObject.value("last_error").toString();
                 qDebug()<<"已获得run状态";
                 requeststate=0;
                 qDebug()<<status;
                 if(status=="")
                 {
                     qDebug()<<"出现错误";
                 }
                 else if(status=="failed")
                 {
                     qDebug()<<"run调用错误"<<last_error;
                 }
                 else if(status=="completed")
                 {
                     getstepidrequest();
                 }
                 else if(status=="0")
                     qDebug()<<"状态为0";
                 else if(status=="queued"||"in_progress")
                 {
                     qDebug()<<"正在等待"<<status;
                     if(getstate==1)
                     {
                    QTimer *timer = new QTimer(this);
                    connect(timer, &QTimer::timeout, this, &Core::getrunstatus);
                    timer->setSingleShot(true);
                    timer->start(2000); // 2秒后触发
                     }
                }

                 else
                     qDebug()<<"好像有问题"<<status;
            }
            else
            {
                qDebug()<<"Error: " <<getrunreply->errorString();
            }
}


//获取run step的message_id
void Core::getstepidrequest() {

        QNetworkRequest request(QUrl("https://api.openai.com/v1/threads/"+thread_id+"/runs/"+run_id+"/steps"));
        request.setRawHeader("OpenAI-Beta", "assistants=v2");
        request.setRawHeader("Authorization", "Bearer " + openaiApiKey.toUtf8());
        if(getstate==1)
        {
        getstepreply = fanetworkManager->get(request);
        qDebug()<<"获取message id已发出";
        //QTimer::singleShot(30000, getstepreply, &QNetworkReply::abort); // 30 seconds timeoutqDebug()<<"GPT输入成功";
        connect(getstepreply, &QNetworkReply::finished, this, &Core::getmessageid);
        getstate=0;
        }
}
void Core::getmessageid()
{
    /*寻找{
  "object": "list",
  "data": [
    {
      "id": "step_abc123",
      "object": "thread.run.step",
      "created_at": 1699063291,
      "run_id": "run_abc123",
      "assistant_id": "asst_abc123",
      "thread_id": "thread_abc123",
      "type": "message_creation",
      "status": "completed",
      "cancelled_at": null,
      "completed_at": 1699063291,
      "expired_at": null,
      "failed_at": null,
      "last_error": null,
      "step_details": {
        "type": "message_creation",
        "message_creation": {
          "message_id": "msg_abc123"
        }
      },
      "usage": {
        "prompt_tokens": 123,
        "completion_tokens": 456,
        "total_tokens": 579
      }
    }
  ],
  "first_id": "step_abc123",
  "last_id": "step_abc456",
  "has_more": false
}中message_id*/

    if (getstepreply->error() == QNetworkReply::NoError)
    {
    QByteArray response = getstepreply->readAll();;
    QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
        QJsonObject jsonObject = jsonResponse.object();
        // 检查是否有 "data" 字段
        if (jsonObject.contains("data") && jsonObject["data"].isArray())
        {
            QJsonArray dataArray = jsonObject["data"].toArray();

            for (const QJsonValue &value : dataArray)
            {
                QJsonObject dataObject = value.toObject();

                if (dataObject.contains("step_details"))
                {
                    QJsonObject stepDetails = dataObject["step_details"].toObject();

                    if (stepDetails.contains("message_creation"))
                    {
                        QJsonObject messageCreation = stepDetails["message_creation"].toObject();

                        // 提取 message_id
                        if (messageCreation.contains("message_id"))
                        {
                            message_id = messageCreation["message_id"].toString();
                            qDebug()<<"已获取messageid";
                            sendgetmessagerequest();
                        }
                    }
                }
            }
        }

    }

    else
    {
        qDebug()<<"getmessageid error: " <<getstepreply->errorString();
    }
}
//获取message
void Core::sendgetmessagerequest() {
    QNetworkRequest request(QUrl("https://api.openai.com/v1/threads/"+thread_id+"/messages/"+message_id));
    request.setRawHeader("OpenAI-Beta", "assistants=v2");
    request.setRawHeader("Authorization", "Bearer " + openaiApiKey.toUtf8());
    getmessagereply = fanetworkManager->get(request);
    qDebug()<<"获取message已发出";
    //QTimer::singleShot(30000, getstepreply, &QNetworkReply::abort); // 30 seconds timeoutqDebug()<<"GPT输入成功";
    connect(getmessagereply, &QNetworkReply::finished, this, &Core::getmessage);
}

void Core::getmessage()
{
    if (getmessagereply->error() == QNetworkReply::NoError)
            {
                QByteArray response = getmessagereply->readAll();
                QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
                QJsonObject jsonObject = jsonResponse.object();
                if (jsonObject.contains("content") && jsonObject["content"].isArray()) {
                    QJsonArray contentArray = jsonObject["content"].toArray();
                    if (!contentArray.isEmpty() && contentArray[0].isObject()) {
                        QJsonObject contentObject = contentArray[0].toObject();
                        if (contentObject.contains("text") && contentObject["text"].isObject()) {
                            QJsonObject textObject = contentObject["text"].toObject();
                            if (textObject.contains("value")) {
                                message = textObject["value"].toString();
                                qDebug()<<"已获取message";
                                content= QString("<span style='font-size:35px;'>%1</span>")
                                        .arg(message);
                                ui->chatoutput->clear();
                                ui->chatoutput->append(content);
                            }
                        }
                    }
                }

            }
            else
            {
                qDebug()<<"getmessage error: " <<getmessagereply->errorString();
            }
}




//GPT-4o API调用
void Core::sendRequest(QString& input) {
    QString userInput = input;
    QJsonObject json;
        json["model"] = "gpt-4o";
        QJsonArray messagesArray;
        QJsonObject messageObject;
        messageObject["role"] = "user";
        messageObject["content"] = userInput;
        messagesArray.append(messageObject);
        json["messages"] = messagesArray;
        json["temperature"] = 1;
        json["max_tokens"] = 1000;
        QNetworkRequest request(QUrl("https://api.openai.com/v1/chat/completions"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Authorization", "Bearer " + openaiApiKey.toUtf8());
        QNetworkReply *reply = networkManager->post(request, QJsonDocument(json).toJson());
        QTimer::singleShot(30000, reply, &QNetworkReply::abort); // 30 seconds timeoutqDebug()<<"GPT输入成功";
    }
//接收处理reply
void Core::on_responseReceived(QNetworkReply *reply) {
    chatResponse="无输出";
    QString Response;
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray response = reply->readAll();
                QJsonDocument jsonResponse = QJsonDocument::fromJson(response);
                Response = jsonResponse["choices"].toArray().first().toObject()["message"].toObject()["content"].toString();
    }
    else {
        Response ="Error: " + reply->errorString();
    }
    chatResponse=Response;
    qDebug()<<"GPT输出完成"<<chatResponse;
         content= QString("<span style='font-size:35px;'>%1</span>")
                .arg(chatResponse);
        ui->chatoutput->clear();
        if(statec==1)
            ui->chatoutput->append(content);
        else if(statec==2)
        {

            everydaynews=content;
            ui->finnewsoutput->append(content);
        }
    reply->deleteLater();
}

//更新每日财经新闻
void Core::updatefiancenews()
{
    statec=2;
    QString userInput = "你是一个财经分析师，简要介绍一下近日的金融形势";
    sendRequest(userInput);
    QString chatoutputtext=chatResponse;
    ui->finnewsoutput->append("正在准备财经新闻……");
    qDebug()<<"输出内容是"<<chatoutputtext;
}
//保存GPT信息到邮件
void Core::on_emailsendinfo_clicked()
{
    ZSmtp *smtp = new ZSmtp;
    connect(smtp, SIGNAL(disconnected()), smtp, SLOT(deleteLater()));	//发送完毕自行销毁
    smtp->sendEmail("915838143@qq.com", "tgpuivudturgbaii","915838143@qq.com", "GPT Response", ui->chatoutput->toPlainText());
}

//保存财经新闻到邮件
void Core::on_emailsendnews_clicked()
{
    ZSmtp *smtp = new ZSmtp;
    connect(smtp, SIGNAL(disconnected()), smtp, SLOT(deleteLater()));	//发送完毕自行销毁
    smtp->sendEmail("915838143@qq.com", "tgpuivudturgbaii","915838143@qq.com", "财经新闻", ui->finnewsoutput->toPlainText());
}

void Core::on_commendbutton_clicked()
{
    QString prompt="现在你是一个投资领域专家，介绍一只有潜力的股票，用中文。要求内容包括"
                   "股票名称、股票简介（简介部分要介绍公司概况，具体经营范围，财务情况）、推荐理由";
    chatwithGPT(prompt,"FinAssistant");
}
