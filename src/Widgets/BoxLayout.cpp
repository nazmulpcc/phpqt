#include "BoxLayout.h"
#include <phpcpp.h>
#include "widget.h"

QBoxLayout *BoxLayout::getNative()
{
    return this->native;
}

void BoxLayout::setNative(QBoxLayout *n)
{
    this->native = n;
    Layout::setNative(n);
}

void BoxLayout::__construct(Php::Parameters &params)
{
    QWidget *parent = nullptr;
    auto direction = static_cast<QBoxLayout::Direction>(params[0].numericValue());
    if (params.size() > 1) {
        parent = params[1].implementation<Widget>()->getNative();
    }
    this->setNative(new QBoxLayout(direction, parent));
}

void BoxLayout::addLayout(Php::Parameters &params)
{
    int stretch = 0;
    auto *layout = params[0].implementation<Layout>();
    if (params.size() > 1) {
        stretch = params[1].numericValue();
    }
    this->native->addLayout(layout->getNative(), stretch);
}

void BoxLayout::addSpacerItem(Php::Parameters &params)
{
    // TODO: Implement QSpacerItem
}

void BoxLayout::addSpacing(Php::Parameters &params)
{
    this->native->addSpacing(params[0].numericValue());
}

void BoxLayout::addStretch(Php::Parameters &params)
{
    int stretch = 0;
    if (params.size() > 0) {
        stretch = params[0].numericValue();
    }
    this->native->addStretch(stretch);
}

void BoxLayout::addStrut(Php::Parameters &params)
{
    this->native->addStretch(params[0].numericValue());
}

void BoxLayout::addWidget(Php::Parameters &params)
{
    auto *widget = params[0].implementation<Widget>();
    int stretch = 0;
    Qt::Alignment alignment = Qt::Alignment();
    if (params.size() > 1) {
        stretch = params[1].numericValue();
    }
    if (params.size() > 2) {
        alignment = static_cast<Qt::Alignment>((int)params[2].numericValue());
    }
    this->native->addWidget(widget->getNative(), stretch, alignment);
}

Php::Value BoxLayout::direction()
{
    return Php::Value(this->native->direction());
}

void BoxLayout::insertItem(Php::Parameters &params)
{
    // TODO: implement QLayoutItem
}

void BoxLayout::insertLayout(Php::Parameters &params)
{
    int index = params[0].numericValue();
    auto *layout = params[1].implementation<Layout>();
    int stretch = 0;
    if (params.size() > 2)
    {
        stretch = params[2].numericValue();
    }
    this->native->insertLayout(index, layout->getNative(), stretch);
}

void BoxLayout::insertSpacerItem(Php::Parameters &params)
{
    // TODO: implement QSpacerItem
}

void BoxLayout::insertSpacing(Php::Parameters &params)
{
    int index = params[0].numericValue();
    int size = params[1].numericValue();
    this->native->insertSpacing(index, size);
}

void BoxLayout::insertStretch(Php::Parameters &params)
{
    int index = params[0].numericValue();
    int stretch = params.size() > 1
        ? params[1].numericValue()
        : 0;
    this->native->insertStretch(index, stretch);
}

void BoxLayout::insertWidget(Php::Parameters &params)
{
    int index = params[0].numericValue();
    auto *widget = params[1].implementation<Widget>();
    int stretch = params.size() > 1
        ? params[2].numericValue()
        : 0;
    Qt::Alignment alignment = Qt::Alignment();
    if (params.size() > 2){
        alignment = static_cast<Qt::Alignment>((int)params[3].numericValue());
    }
    this->native->insertWidget(index, widget->getNative(), stretch, alignment);
}

void BoxLayout::setDirection(Php::Parameters &params)
{
    auto direction = static_cast<QBoxLayout::Direction>(params[0].numericValue());
    this->native->setDirection(direction);
}

void BoxLayout::setSpacing(Php::Parameters &params)
{
    this->native->setSpacing(params[0].numericValue());
}

void BoxLayout::setStretch(Php::Parameters &params)
{
    this->native->setStretch(params[0].numericValue(), params[1].numericValue());
}

void BoxLayout::setStretchFactor(Php::Parameters &params)
{
    auto widget = params[0].implementation<Widget>();
    this->native->setStretchFactor(widget->getNative(), params[1].numericValue());
}

Php::Value BoxLayout::spacing()
{
    return Php::Value(this->native->spacing());
}

Php::Value BoxLayout::stretch(Php::Parameters &params)
{
    return Php::Value(this->native->stretch(params[0].numericValue()));
}
