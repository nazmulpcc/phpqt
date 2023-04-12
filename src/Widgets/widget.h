#ifndef WIDGET_H
#define WIDGET_H

#include "../Core/Object.h"
#include <phpcpp.h>
#include <QtWidgets/QWidget>

class Widget : public Object
{
private:
    QWidget *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\Widget";
    
    virtual QWidget *getNative();
    virtual void setNative(QWidget * n);

    void __construct(Php::Parameters &params);
    Php::Value close();
    void setCursor(Php::Parameters &params);
    void setDisabled(Php::Parameters &params);
    void setFocus();
    void setGeometry(Php::Parameters &params);
    void setHidden(Php::Parameters &params);
    void setLayout(Php::Parameters &params);
    void setMaximumHeight(Php::Parameters &params);
    void setMaximumSize(Php::Parameters &params);
    void setMaximumWidth(Php::Parameters &params);
    void setMinimumSize(Php::Parameters &params);
    void setMinimumHeight(Php::Parameters &params);
    void setMinimumWidth(Php::Parameters &params);
    void setStyleSheet(Php::Parameters &params);
    void setWindowTitle(Php::Parameters &params);
    void show();
    void showFullScreen();
    void showMaximized();
    void showMinimized();
    void showNormal();


    static Php::Class<Widget> _DEFINITION()
    {
        Php::Class<Widget> definition(Widget::CLASSPATH.c_str());

        definition.method<&Widget::__construct>("__construct", {
            Php::ByRef("parent", Php::Type::Object, false)
        });
        definition.method<&Widget::close>("close");
        definition.method<&Widget::setCursor>("setCursor", {
            Php::ByVal("cursor", Php::Type::Numeric, true)
        });
        definition.method<&Widget::setDisabled>("setDisabled", {
            Php::ByVal("disabled", Php::Type::Bool, true)
        });
        definition.method<&Widget::setFocus>("setFocus");
        definition.method<&Widget::setGeometry>("setGeometry", {
                Php::ByVal("x", Php::Type::Numeric, true),
                Php::ByVal("y", Php::Type::Numeric, true),
                Php::ByVal("w", Php::Type::Numeric, true),
                Php::ByVal("h", Php::Type::Numeric, true),
        });
        definition.method<&Widget::setHidden>("setHidden", {
            Php::ByVal("hidden", Php::Type::Bool, true)
        });
        definition.method<&Widget::setLayout>("setLayout", {
            Php::ByRef("layout", Php::Type::Object, true)
        });
        definition.method<&Widget::setMaximumHeight>("setMaximumHeight", {Php::ByVal("height", Php::Type::Numeric, true)});
        definition.method<&Widget::setMaximumSize>("setMaximumSize", {
            Php::ByVal("width", Php::Type::Numeric, true),
            Php::ByVal("height", Php::Type::Numeric, true)
        });
        definition.method<&Widget::setMaximumWidth>("setMaximumWidth", {Php::ByVal("width", Php::Type::Numeric, true)});
        definition.method<&Widget::setMinimumHeight>("setMinimumHeight", {Php::ByVal("height", Php::Type::Numeric, true)});
        definition.method<&Widget::setMinimumSize>("setMinimumSize", {
            Php::ByVal("width", Php::Type::Numeric, true),
            Php::ByVal("height", Php::Type::Numeric, true)
        });
        definition.method<&Widget::setMinimumWidth>("setMinimumWidth", {Php::ByVal("width", Php::Type::Numeric, true)});
        definition.method<&Widget::setStyleSheet>("setStyleSheet", {
            Php::ByVal("style", Php::Type::String, true),
        });
        definition.method<&Widget::setWindowTitle>("setWindowTitle", {Php::ByVal("title", Php::Type::String, true)});
        definition.method<&Widget::show>("show");
        definition.method<&Widget::showFullScreen>("showFullScreen");
        definition.method<&Widget::showMaximized>("showMaximized");
        definition.method<&Widget::showMinimized>("showMinimized");
        definition.method<&Widget::showNormal>("showNormal");

        return definition;
    }
};

#endif