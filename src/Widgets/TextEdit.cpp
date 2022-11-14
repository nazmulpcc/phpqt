#include "textedit.h"
#include <QtWidgets/QTextEdit>

void TextEdit::__construct()
{
    this->native = new QTextEdit;
}

void TextEdit::show()
{
    this->native->show();
}