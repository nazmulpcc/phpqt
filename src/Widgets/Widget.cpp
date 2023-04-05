#include "widget.h"
#include <QtWidgets/QWidget>

QWidget* Widget::getNative()
{
    return this->native;
}

void Widget::setGeometry(Php::Parameters &params)
{
    int x = params[0].numericValue();
    int y = params[1].numericValue();
    int w = params[2].numericValue();
    int h = params[3].numericValue();

    try {
        this->native->setGeometry(x, y, w, h);
    } catch (...) {
        throw Php::Exception("Invalid parameter passed.");
    }
}

void Widget::setNative(QWidget* n)
{
    this->native = n;
}

void Widget::show()
{
    this->native->show();
}