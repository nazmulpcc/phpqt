#include <phpcpp.h>
#include "pushbutton.h"

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
    this->native = new QPushButton(QString::fromStdString(text), parent);
    setNative(this->native);
}

void PushButton::onPressed(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->native->connect(this->native, &QPushButton::pressed, [callback]{
        callback();
    });
}

void PushButton::onClicked(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->native->connect(this->native, &QPushButton::clicked, [callback]{
        callback();
    });
}

void PushButton::onReleased(Php::Parameters &params)
{
    Php::Value callback = params[0];
    this->native->connect(this->native, &QPushButton::released, [callback]{
        callback();
    });;
}
