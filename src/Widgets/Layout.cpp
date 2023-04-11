#include "Layout.h"
#include <QtWidgets/QLayout>
#include "widget.h"

void Layout::setNative(QLayout *n) {
    this->native = n;
    Object::setNative(n);
}

Php::Value Layout::activate()
{
    return Php::Value(this->native->activate());
}

void Layout::addWidget(Php::Parameters &params)
{
    auto widget = params[0].implementation<Widget>();
    this->native->addWidget(widget->getNative());
}

Php::Value Layout::getContentsMargins(Php::Parameters &params)
{
    int left, top, right, bottom;
    this->native->getContentsMargins(&left, &top, &right, &bottom);
    if (params.size() > 0) {
        params[0] = left;
    }
    if (params.size() > 1) {
        params[1] = top;
    }
    if (params.size() > 2) {
        params[2] = right;
    }
    if (params.size() > 3) {
        params[3] = bottom;
    }
    Php::Value returnValue = {left, top, right, bottom};

    return returnValue;
}

Php::Value Layout::isEnabled()
{
    return Php::Value(this->native->isEnabled());
}

Php::Value Layout::menuBar()
{
    return Php::Object(Widget::CLASSPATH.c_str(), this->native->menuBar());
}

Php::Value Layout::parentWidget()
{
    return Php::Object(Widget::CLASSPATH.c_str(), this->native->menuBar());
}

void Layout::removeItem(Php::Parameters &params)
{
    // TODO: implement php class for QLayoutItem
}

void Layout::removeWidget(Php::Parameters &params)
{
    auto widget = params[0].implementation<Widget>();
    this->native->removeWidget(widget->getNative());
}

Php::Value Layout::setAlignment(Php::Parameters &params)
{
    auto widget = params[0].implementation<Widget>();
    auto alignment = static_cast<Qt::Alignment>((int) params[1].numericValue());
    return this->native->setAlignment(widget->getNative(), alignment);
}

void Layout::setContentsMargins(Php::Parameters &params)
{
    this->native->setContentsMargins(
        params[0].numericValue(),
        params[1].numericValue(),
        params[2].numericValue(),
        params[3].numericValue()
    );
}

void Layout::setEnabled(Php::Parameters &params)
{
    this->native->setEnabled(params[0].boolValue());
}

void Layout::setMenuBar(Php::Parameters &params)
{
    this->native->setMenuBar(params[0].implementation<Widget>()->getNative());
}

void Layout::setSizeConstraint(Php::Parameters &params)
{
    auto constraint = static_cast<QLayout::SizeConstraint>(params[0].numericValue());
    this->native->setSizeConstraint(constraint);
}

void Layout::setSpacing(Php::Parameters &params)
{
    this->native->setSpacing(params[0].numericValue());
}

Php::Value Layout::sizeConstraint()
{
    return Php::Value((int) this->native->sizeConstraint());
}

Php::Value Layout::spacing()
{
    return Php::Value(this->native->spacing());
}

void Layout::update()
{
    this->native->update();
}

QLayout *Layout::getNative()
{
    return this->native;
}