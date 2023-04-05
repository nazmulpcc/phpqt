#include "widget.h"
#include "../macros.h"
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
    OVERRIDE_METHOD(show)

    static Php::Class<TextEdit> _DEFINITION()
    {
        Php::Class<TextEdit> textedit("Qt\\Widgets\\TextEdit");
        textedit.method<&TextEdit::__construct>("__construct");
        textedit.method<&TextEdit::show>("show");
        textedit.method<&TextEdit::copy>("copy");
        textedit.method<&TextEdit::toPlainText>("toPlainText");

        return textedit;
    }
};
