#include "widget.h"
#include <QtWidgets/QWidget>

QWidget* Widget::getNative()
{
    return this->native;
}

void Widget::setNative(QWidget* n)
{
    this->native = n;
}

void Widget::show()
{
    this->native->show();
}