#include "widget.h"
#include "Layout.h"
#include <QtWidgets/QWidget>

Widget::Widget()
{
    native = new QWidget;
}

QWidget *Widget::getNative()
{
    return this->native;
}

Php::Value Widget::close()
{
    return Php::Value(this->native->close());
}

void Widget::setDisabled(Php::Parameters &params)
{
    this->native->setDisabled(params[0].boolValue());
}

void Widget::setFocus()
{
    this->native->setFocus();
}

void Widget::setHidden(Php::Parameters &params)
{
    this->native->setHidden(params[0].boolValue());
}

void Widget::setLayout(Php::Parameters &params)
{
    this->native->setLayout(params[0].implementation<Layout>()->getNative());
}

void Widget::setStyleSheet(Php::Parameters &params)
{
    this->native->setStyleSheet(QString::fromStdString(params[0].stringValue()));
}

void Widget::setWindowTitle(Php::Parameters &params)
{
    this->native->setWindowTitle(QString::fromStdString(params[0].stringValue()));
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

void Widget::showFullScreen()
{
    this->native->showFullScreen();
}

void Widget::showMaximized()
{
    this->native->showMaximized();
}

void Widget::showMinimized()
{
    this->native->showMinimized();
}

void Widget::showNormal()
{
    this->native->showNormal();
}
