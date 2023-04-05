#include <phpcpp.h>
#include <QtWidgets/QTextEdit>

class TextEdit : public Php::Base
{
private:
    QTextEdit* native;

public:
    void __construct();
    void show();

    QTextEdit* getNative();
    void setNative(QTextEdit *n);

    static Php::Class<TextEdit> _DEFINITION()
    {
        Php::Class<TextEdit> textedit("Qt\\Widgets\\TextEdit");
        textedit.method<&TextEdit::__construct>("__construct");
        textedit.method<&TextEdit::show>("show");

        return textedit;
    }
};