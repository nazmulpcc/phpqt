#include <phpcpp.h>
#include "pushbutton.h"
#include "mainwindow.h"

void PushButton::__construct(Php::Parameters &params)
{
    std::string text = "";
    QWidget *parent = nullptr;

    if (params.size() >= 1)
    {
        Widget *temp = params[0].implementation<Widget>();
        if (temp == nullptr){
            text = params[0].stringValue();
        }else{
            parent = temp->getNative();
        }
    }
    if (params.size() == 2){
        parent = params[1].implementation<Widget>()->getNative();
    }
    this->button = new QPushButton(QString::fromStdString(text), parent);
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
