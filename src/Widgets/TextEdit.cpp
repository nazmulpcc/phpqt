#include "textedit.h"
#include <QtWidgets/QTextEdit>

void TextEdit::__construct(Php::Parameters &params)
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
    this->textedit = new QTextEdit(QString::fromStdString(text), parent->getNative());
    this->native = this->textedit;
}

Php::Value TextEdit::toPlainText()
{
    return Php::Value(this->textedit->toPlainText().toStdString());
}

void TextEdit::copy()
{
    this->textedit->copy();
}