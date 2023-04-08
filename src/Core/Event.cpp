#include "Event.h"
#include <QtCore/QEvent>

void Event::setNative(QEvent *n)
{
    this->native = n;
}

QEvent *Event::getNative(QEvent *n)
{
    return this->native;
}

void Event::__construct(Php::Parameters &params)
{
    auto type = static_cast<QEvent::Type>(params[0].numericValue());
    this->native = new QEvent(type);
}

void Event::accept()
{
    this->native->accept();
}

void Event::ignore()
{
    this->native->ignore();
}

Php::Value Event::isAccepted()
{
    return Php::Value(this->native->isAccepted());
}

void Event::setAccepted(Php::Parameters &params)
{
    this->native->setAccepted(params[0].boolValue());
}

Php::Value Event::spontaneous()
{
    return Php::Value(this->native->spontaneous());
}

Php::Value Event::type()
{
    return Php::Value((int) this->native->type());
}
