#include "WebPageScreenshot.h"
#include <QApplication>
#include <QPainter>
#include <QPixmap>

/*WebPageScreenshot::WebPageScreenshot() {
    connect(&webView, &QWebView::loadFinished, this, &WebPageScreenshot::onLoadFinished);
}

void WebPageScreenshot::capture(const QString &url, const QString &outputFile) {
    outputFileName = outputFile;
    webView.load(QUrl(url));
}

void WebPageScreenshot::onLoadFinished(bool ok) {
    if (ok) {
        webView.setFixedSize(1024, 768);
        QPixmap pixmap(webView.size());
        QPainter painter(&pixmap);
        webView.render(&painter);
        painter.end();
        pixmap.save(outputFileName);
        QApplication::quit();
    } else {
        qWarning("Failed to load the page.");
        QApplication::quit();
    }
}
*/
