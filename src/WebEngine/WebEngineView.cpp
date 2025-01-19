#include "WebEngineView.h"

QWebEngineView *WebEngineView::getNative()
{
    return this->native;
}

void WebEngineView::setNative(QWebEngineView *n)
{
    this->native = n;
}

void WebEngineView::__construct()
{
    this->native = new QWebEngineView();
    setNative(this->native);
}

void WebEngineView::setUrl(Php::Parameters &params)
{
    const QUrl url = QUrl(QString::fromStdString(params[0].stringValue()));
    this->native->setUrl(url);
}

void WebEngineView::printToPdf(Php::Parameters &params)
{
    QString filePath = QString::fromStdString(params[0].stringValue());
    this->native->printToPdf(filePath);
}

void WebEngineView::onLoadFinished(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->native->connect(this->native, &QWebEngineView::loadFinished, [callback](bool ok)
                          { callback(Php::Value(ok)); });
}

void WebEngineView::onPdfPrintingFinished(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->native->connect(this->native, &QWebEngineView::pdfPrintingFinished, [callback](const QString &filePath, bool ok)
                          { callback(Php::Value(filePath.toStdString()), Php::Value(ok)); });
}

void WebEngineView::onUrlChanged(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->native->connect(this->native, &QWebEngineView::urlChanged, [callback](const QUrl &url)
                          { callback(Php::Value(url.toString().toStdString())); });
}

void WebEngineView::onTitleChanged(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->native->connect(this->native, &QWebEngineView::titleChanged, [callback](const QString &title)
                          { callback(Php::Value(title.toStdString())); });
}

Php::Value WebEngineView::url(Php::Parameters &params)
{
    return Php::Value(this->native->url().toString().toStdString());
}

Php::Value WebEngineView::title(Php::Parameters &params)
{
    return Php::Value(this->native->title().toStdString());
}
