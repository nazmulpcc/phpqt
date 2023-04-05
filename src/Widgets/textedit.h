#include "widget.h"
#include <phpcpp.h>
#include <QtWidgets/QTextEdit>

class TextEdit : public Widget
{
private:
    QTextEdit *textedit;

public:
    void __construct();
    Php::Value toPlainText();
    void copy();

    static Php::Class<TextEdit> _DEFINITION()
    {
        Php::Class<TextEdit> textedit("Qt\\Widgets\\TextEdit");
        textedit.method<&TextEdit::__construct>("__construct");
        textedit.method<&TextEdit::copy>("copy");
        textedit.method<&TextEdit::toPlainText>("toPlainText");

        return textedit;
    }
};
