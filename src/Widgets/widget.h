#ifndef WIDGET_H
#define WIDGET_H

#include <phpcpp.h>
#include <QtWidgets/QWidget>

class Widget : public Php::Base
{
public:
    QWidget *native;

    QWidget *getNative();
    virtual void setGeometry(Php::Parameters &params);
    void setNative(QWidget * n);
    virtual void show();

    static Php::Class<Widget> _DEFINITION()
    {
        Php::Class<Widget> widget("Qt\\Widgets\\Widget", Php::Abstract);

        return widget;
    }
};

#endif