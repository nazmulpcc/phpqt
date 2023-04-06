#include "textedit.h"
#include <QtWidgets/QTextEdit>

void TextEdit::__construct(Php::Parameters &params)
{
    std::string text = "";
    QWidget *parent = nullptr;

    if (params.size() == 0){
        text = "";
        parent = nullptr;
    }
    if (params.size() >= 1){
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
    this->native = new QTextEdit(QString::fromStdString(text), parent);
    setNative(this->native);
}

Php::Value TextEdit::toPlainText()
{
    return Php::Value(this->native->toPlainText().toStdString());
}

void TextEdit::copy()
{
    this->native->copy();
}