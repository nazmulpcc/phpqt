#ifndef WEBENGINEVIEW_H
#define WEBENGINEVIEW_H

#include <phpcpp.h>
#include "../Widgets/widget.h"
#include <QWebEngineView>
#include <QString>
#include <QUrl>

class WebEngineView : public Widget
{
private:
    QWebEngineView *native;

public:
    inline static const char *CLASSPATH = "Qt\\WebEngine\\WebEngineView";

    QWebEngineView *getNative();
    void setNative(QWebEngineView *n);

    void __construct(Php::Parameters &params);
    void setUrl(Php::Parameters &params);
    void printToPdf(Php::Parameters &params);

    void onLoadFinished(Php::Parameters &params);
    void onPdfPrintingFinished(Php::Parameters &params);
    void onUrlChanged(Php::Parameters &params);
    void onTitleChanged(Php::Parameters &params);

    Php::Value
    url(Php::Parameters &params);
    Php::Value title(Php::Parameters &params);

    static Php::Class<WebEngineView> _DEFINITION()
    {
        Php::Class<WebEngineView> definition(WebEngineView::CLASSPATH);

        definition.method<&WebEngineView::__construct>("__construct");
        definition.method<&WebEngineView::setUrl>("setUrl", {Php::ByVal("url", Php::Type::String, true)});
        definition.method<&WebEngineView::printToPdf>("printToPdf", {Php::ByVal("filePath", Php::Type::String, true)});

        // signals
        definition.method<&WebEngineView::onLoadFinished>("onLoadFinished", {Php::ByVal("callback", Php::Type::Callable, true)});
        definition.method<&WebEngineView::onPdfPrintingFinished>("onPdfPrintingFinished", {Php::ByVal("callback", Php::Type::Callable, true)});
        definition.method<&WebEngineView::onUrlChanged>("onUrlChanged", {Php::ByVal("callback", Php::Type::Callable, true)});
        definition.method<&WebEngineView::onTitleChanged>("onTitleChanged", {Php::ByVal("callback", Php::Type::Callable, true)});

        definition.method<&WebEngineView::url>("url");
        definition.method<&WebEngineView::title>("title");

        return definition;
    }
};

#endif
