#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ChatDialog : public QDialog {
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();
    void on_sendButton_clicked(QString& input);
    void on_responseReceived(QNetworkReply *reply);
    QString chatResponse;

private slots:

private:
    QNetworkAccessManager *networkManager;
    QString openaiApiKey;

};

#endif // CHATDIALOG_H
