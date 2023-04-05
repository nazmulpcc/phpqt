#include "textedit.h"
#include <QtWidgets/QTextEdit>

void TextEdit::__construct()
{
    this->setNative(new QTextEdit);
}

void TextEdit::show()
{
    this->native->show();
}

QTextEdit *TextEdit::getNative()
{
    return this->native;
}

void TextEdit::setNative(QTextEdit *n)
{
    this->native = n;
}