#include <phpcpp.h>
#include "pushbutton.h"
#include "mainwindow.h"

void PushButton::__construct(Php::Parameters &params)
{
    QString name = QString::fromStdString((std::string)params[0]);
    MainWindow *parent = (MainWindow *) params[1].implementation();

    this->native = new QPushButton(name, parent->getNative());
}

void PushButton::onPressed(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->native->connect(this->native, &QPushButton::pressed, callback);
}

void PushButton::onClicked(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->native->connect(this->native, &QPushButton::clicked, callback);
}

void PushButton::onReleased(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->native->connect(this->native, &QPushButton::released, callback);
}