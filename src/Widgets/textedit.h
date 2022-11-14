#include <phpcpp.h>
#include "widget.h"
#include <QtWidgets/QTextEdit>

class TextEdit : public Widget
{
private:
    QTextEdit *native;

public:
    void __construct();
    void show();

    static Php::Class<TextEdit> _DEFINITION()
    {
        Php::Class<TextEdit> textedit("Qt\\Widgets\\TextEdit");
        textedit.method<&TextEdit::__construct>("__construct");
        textedit.method<&TextEdit::show>("show");

        return textedit;
    }
};