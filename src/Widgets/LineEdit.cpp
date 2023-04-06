#include "LineEdit.h"
#include <phpcpp.h>

void LineEdit::__construct(Php::Parameters &params)
{
    std::string contents = "";
    QWidget *parent = nullptr;
    Widget *temp;
    if (params.size() >= 1) {
        temp = params[0].implementation<Widget>();
        if (temp == nullptr) {
            contents = params[0].stringValue();
        } else {
            parent = temp->getNative();
        }
    }
    if (params.size() >= 2) {
        temp = params[1].implementation<Widget>();
        if (temp != nullptr) {
            parent = temp->getNative();
        } else {
            throw Php::Exception("Invalid parameter supplied");
        }
    }
    this->native = new QLineEdit(QString::fromStdString(contents), parent);
    setNative(this->native);
}

Php::Value LineEdit::inputMask()
{
    return Php::Value(this->native->inputMask().toStdString());
}

Php::Value LineEdit::isModified()
{
    return Php::Value(this->native->isModified());
}

Php::Value LineEdit::isReadOnly()
{
    return Php::Value(this->native->isReadOnly());
}

Php::Value LineEdit::placeholderText() {
    return Php::Value(this->native->placeholderText().toStdString());
}

void LineEdit::setEchoMode(Php::Parameters &params)
{
    auto mode = static_cast<QLineEdit::EchoMode>(params[0].numericValue());
    this->native->setEchoMode(mode);
}

void LineEdit::setInputMask(Php::Parameters &params)
{
    this->native->setInputMask(QString::fromStdString(params[0].stringValue()));
}

void LineEdit::setMaxLength(Php::Parameters &params)
{
    this->native->setMaxLength(params[0].numericValue());
}

void LineEdit::setPlaceholderText(Php::Parameters &params) {
    this->native->setPlaceholderText(QString::fromStdString(params[0].stringValue()));
}

void LineEdit::setReadOnly(Php::Parameters &params)
{
    this->native->setReadOnly(params[0].boolValue());
}

void LineEdit::setSelection(Php::Parameters &params)
{
    this->native->setSelection(params[0].numericValue(), params[1].numericValue());
}

void LineEdit::setValidator(Php::Parameters &params)
{
    // TODO: implement QValidator class first
}

Php::Value LineEdit::text()
{
    return Php::Value(this->native->text().toStdString());
}
