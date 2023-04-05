#include "textedit.h"
#include <QtWidgets/QTextEdit>

void TextEdit::__construct()
{
    this->native = new QTextEdit;
    this->textedit = dynamic_cast<QTextEdit *>(this->native);
}

Php::Value TextEdit::toPlainText()
{
    return Php::Value(this->textedit->toPlainText().toStdString());
}

void TextEdit::copy()
{
    this->textedit->copy();
}