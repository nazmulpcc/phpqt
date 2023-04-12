#include "widget.h"
#include "Layout.h"
#include <QtWidgets/QWidget>

QWidget *Widget::getNative()
{
    return this->native;
}

void Widget::__construct(Php::Parameters &params)
{
    QWidget *parent = nullptr;
    if (params.size() > 0) {
        parent = params[0].implementation<Widget>()->getNative();
    }
    this->setNative(new QWidget(parent));
}

Php::Value Widget::close()
{
    return Php::Value(this->native->close());
}

void Widget::setCursor(Php::Parameters &params)
{
    auto shape = static_cast<Qt::CursorShape>(params[0].numericValue());
    auto *cursor = new QCursor(shape);
    this->native->setCursor(*cursor);
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

void Widget::setMaximumHeight(Php::Parameters &params)
{
    this->native->setMaximumHeight(params[0].numericValue());
}

void Widget::setMaximumSize(Php::Parameters &params)
{
    this->native->setMaximumSize(
        params[0].numericValue(),
        params[1].numericValue()
    );
}

void Widget::setMaximumWidth(Php::Parameters &params)
{
    this->native->setMaximumWidth(params[0].numericValue());
}

void Widget::setMinimumSize(Php::Parameters &params)
{
    this->native->setMinimumSize(
        params[0].numericValue(),
        params[1].numericValue()
    );
}

void Widget::setMinimumHeight(Php::Parameters &params)
{
    this->native->setMinimumHeight(params[0].numericValue());
}

void Widget::setMinimumWidth(Php::Parameters &params)
{
    this->native->setMinimumWidth(params[0].numericValue());
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
    Object::setNative(n);
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
