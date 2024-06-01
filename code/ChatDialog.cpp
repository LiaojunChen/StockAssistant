#include "ChatDialog.h"
#include "ui_core.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QTimer>
#include"core.h"
ChatDialog::ChatDialog(QWidget *parent)
    : QDialog(parent) {

    networkManager = new QNetworkAccessManager(this);
    openaiApiKey = "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"; // Replace with your OpenAI API key
    connect(networkManager, &QNetworkAccessManager::finished, this, &ChatDialog::on_responseReceived);
}

ChatDialog::~ChatDialog() {

}

void ChatDialog::on_sendButton_clicked(QString& input) {
    QString userInput = input;
    QJsonObject json;
        json["model"] = "gpt-3.5-turbo"; // Adjust model as needed
        QJsonArray messagesArray;
        QJsonObject messageObject;
        messageObject["role"] = "user";
        messageObject["content"] = userInput;
        messagesArray.append(messageObject);
        json["messages"] = messagesArray;
        json["temperature"] = 0.7;
        json["max_tokens"] = 1000;

        QNetworkRequest request(QUrl("https://api.openai.com/v1/chat/completions"));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        request.setRawHeader("Authorization", "Bearer " + openaiApiKey.toUtf8());

        QNetworkReply *reply = networkManager->post(request, QJsonDocument(json).toJson());
        QTimer::singleShot(60000, reply, &QNetworkReply::abort); // 30 seconds timeout
        //QJsonDocument doc(json);
        //networkManager->post(request, doc.toJson());
        qDebug()<<"GPT输入成功";
    }
void ChatDialog::on_responseReceived(QNetworkReply *reply) {
    chatResponse="无输出";
    QString Response;
    qDebug()<<"开始发送prompt"<<chatResponse;
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
    ui->chatoutput->append(chatResponse)；
    reply->deleteLater();
}
