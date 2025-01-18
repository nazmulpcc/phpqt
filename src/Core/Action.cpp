#include "Action.h"
#include "../Gui/Icon.h"

QAction *Action::getNative()
{
    return this->native;
}

void Action::setNative(QAction *n)
{
    this->native = n;
    Object::setNative(n);
}

void Action::__construct(Php::Parameters &params)
{
    QAction *action;
    Object *parent;
    QString text;
    Icon *icon;
    if (params.size() == 1)
    {
        parent = params[0].implementation<Object>();
        action = new QAction(parent->getNative());
    }
    else if (params.size() == 2)
    {
        text = QString::fromStdString(params[0].stringValue());
        parent = params[1].implementation<Object>();
        action = new QAction(text, parent->getNative());
    }
    else
    {
        icon = params[0].implementation<Icon>();
        text = QString::fromStdString(params[1].stringValue());
        parent = params[2].implementation<Object>();
        action = new QAction(*icon->getNative(), text, parent->getNative());
    }
    this->setNative(action);
}
