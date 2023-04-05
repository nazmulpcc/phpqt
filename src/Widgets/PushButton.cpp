#include <phpcpp.h>
#include "pushbutton.h"
#include "mainwindow.h"

void PushButton::__construct(Php::Parameters &params)
{
    std::string text;
    Widget *parent;

    if (params.size() == 0){
        text = "";
        parent = nullptr;
    }
    if (params.size() >= 1){
        text = params[0].stringValue();
    }
    if (params.size() == 2){
        parent = params[1].implementation<Widget>();
    }
    this->button = new QPushButton(QString::fromStdString(text), parent->getNative());
    this->native = this->button;
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
