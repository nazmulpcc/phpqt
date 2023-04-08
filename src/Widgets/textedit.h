#include "widget.h"
#include <phpcpp.h>
#include <QtWidgets/QTextEdit>

class TextEdit : public Widget
{
private:
    QTextEdit *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\TextEdit";

    void __construct(Php::Parameters &params);
    Php::Value toPlainText();
    void copy();

    static Php::Class<TextEdit> _DEFINITION()
    {
        Php::Class<TextEdit> textedit(TextEdit::CLASSPATH.c_str());
        textedit.method<&TextEdit::__construct>("__construct", {
            Php::ByVal("text", Php::Type::String, false),
            Php::ByRef("parent", Php::Type::Object, false)
        });
        textedit.method<&TextEdit::copy>("copy");
        textedit.method<&TextEdit::toPlainText>("toPlainText");

        return textedit;
    }
};
