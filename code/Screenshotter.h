#ifndef WEBCAPTURE_H
#define WEBCAPTURE_H
#include <QScreen>
#include <QTimer>
#include <QDebug>
#include <QApplication>
//#include <QWebView>
#include <QScreen>
#include <QTimer>
#include <QDebug>
#include<QUrl>
#include<qdebug.h>
#include <QString>
#include <QDebug>
#include<qdebug.h>
#include <QDebug>
#include <QObject>
#include <QRect>
#include <QString>

#include <QWidget>
//#include <QtWebKitWidgets/QWebView>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE
void viewclicktest();
//QWebView *view;
class Screenshotter : public QWidget
{
    Q_OBJECT

public:
   Screenshotter(QWidget *parent = nullptr);
    ~Screenshotter();

private slots:


private:
    Ui::Widget *ui;

};


#endif // WEBCAPTURE_H
