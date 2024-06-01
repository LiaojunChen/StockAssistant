#ifndef WEBPAGESCREENSHOT_H
#define WEBPAGESCREENSHOT_H

#include <QObject>
//#include <QWebView>

class WebPageScreenshot : public QObject {
    Q_OBJECT/*
public:
    WebPageScreenshot();
    void capture(const QString &url, const QString &outputFile);

private slots:
    void onLoadFinished(bool ok);

private:
    QWebView webView;
    QString outputFileName;*/
};

#endif // WEBPAGESCREENSHOT_H
