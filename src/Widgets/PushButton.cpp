#include "../macros.h"
#include <phpcpp.h>
#include "pushbutton.h"
#include "mainwindow.h"

void PushButton::__construct(Php::Parameters &params)
{
    QString name = QString::fromStdString(params[0].stringValue());
    MainWindow *parent = (MainWindow *) params[1].implementation();

    this->native = new QPushButton(name, parent->getNative());
    this->button = dynamic_cast<QPushButton *>(this->native);
}

void PushButton::onPressed(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->button->connect(this->button, &QPushButton::pressed, callback);
}

void PushButton::onClicked(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->button->connect(this->button, &QPushButton::clicked, callback);
}

void PushButton::onReleased(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->button->connect(this->button, &QPushButton::released, callback);
}

FORWARD_CALL(PushButton, Widget, show)
