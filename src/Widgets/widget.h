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
    Widget();
    
    virtual QWidget *getNative();
    virtual void setNative(QWidget * n);

    Php::Value close();
    void setDisabled(Php::Parameters &params);
    void setFocus();
    void setGeometry(Php::Parameters &params);
    void setHidden(Php::Parameters &params);
    void setLayout(Php::Parameters &params);
    void setStyleSheet(Php::Parameters &params);
    void setWindowTitle(Php::Parameters &params);
    void show();
    void showFullScreen();
    void showMaximized();
    void showMinimized();
    void showNormal();


    static Php::Class<Widget> _DEFINITION()
    {
        Php::Class<Widget> definition("Qt\\Widgets\\Widget");

        definition.method<&Widget::close>("close");
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
            Php::ByVal("layout", Php::Type::Object, true)
        });
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