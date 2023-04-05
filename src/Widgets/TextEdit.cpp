#include "textedit.h"
#include <QtWidgets/QTextEdit>

void TextEdit::__construct()
{
    this->setNative(new QTextEdit);
    this->textedit = dynamic_cast<QTextEdit *>(this->native);
}

FORWARD_CALL(TextEdit, Widget, show)
