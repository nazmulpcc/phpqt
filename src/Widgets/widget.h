#ifndef WIDGET_H
#define WIDGET_H

#include<phpcpp.h>
#include<QtWidgets/QWidget>

class Widget: public Php::Base
{
protected:
    QWidget *native;

public:
    QWidget* getNative();

    static Php::Class<Widget> _DEFINITION()
    {
        Php::Class<Widget> widget("Qt\\Widgets\\Widget");

        return widget;
    }
};

#endif