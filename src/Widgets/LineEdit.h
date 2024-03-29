#ifndef PHPQT_LINEEDIT_H
#define PHPQT_LINEEDIT_H

#include "widget.h"
#include <phpcpp.h>
#include <QtWidgets/QLineEdit>


class LineEdit : public Widget {
private:
    QLineEdit *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\LineEdit";

    void __construct(Php::Parameters &params);

    void clear();
    Php::Value inputMask();
    Php::Value isModified();
    Php::Value isReadOnly();
    Php::Value placeholderText();

    void setEchoMode(Php::Parameters &params);
    void setInputMask(Php::Parameters &params);
    void setMaxLength(Php::Parameters &params);
    void setPlaceholderText(Php::Parameters &params);
    void setReadOnly(Php::Parameters &params);
    void setSelection(Php::Parameters &params);
    void setText(Php::Parameters &params);
    void setValidator(Php::Parameters &params);

    void textChanged(Php::Parameters &params);
    void textEdited(Php::Parameters &params);

    Php::Value text();

    static Php::Class<LineEdit> _DEFINITION() {
        Php::Class<LineEdit> lineEdit(LineEdit::CLASSPATH.c_str());

        lineEdit.constant("Normal", QLineEdit::Normal);
        lineEdit.constant("NoEcho", QLineEdit::NoEcho);
        lineEdit.constant("Password", QLineEdit::Password);
        lineEdit.constant("PasswordEchoOnEdit", QLineEdit::PasswordEchoOnEdit);

        lineEdit.method<&LineEdit::__construct>("__construct", {
            Php::ByVal("contents", Php::Type::String, false),
            Php::ByRef("parent", Php::Type::Object, false)
        });

        lineEdit.method<&LineEdit::clear>("clear");
        lineEdit.method<&LineEdit::inputMask>("inputMask");
        lineEdit.method<&LineEdit::isModified>("isModified");
        lineEdit.method<&LineEdit::isReadOnly>("isReadOnly");
        lineEdit.method<&LineEdit::placeholderText>("placeholderText");

        lineEdit.method<&LineEdit::setEchoMode>("setEchoMode", {Php::ByVal("mask", Php::Type::String, true)});
        lineEdit.method<&LineEdit::setInputMask>("setInputMask", { Php::ByVal("mask", Php::Type::String, true) });
        lineEdit.method<&LineEdit::setMaxLength>("setMaxLength", { Php::ByVal("length", Php::Type::Numeric, true) });
        lineEdit.method<&LineEdit::setPlaceholderText>("setPlaceholderText", { Php::ByVal("contents", Php::Type::String, true) });
        lineEdit.method<&LineEdit::setReadOnly>("setReadOnly", {Php::ByVal("readOnly", Php::Type::Bool, true)});
        lineEdit.method<&LineEdit::setSelection>("setSelection", {
            Php::ByVal("start", Php::Type::Numeric, true),
            Php::ByVal("end", Php::Type::Numeric, true)
        });
        lineEdit.method<&LineEdit::setText>("setText", {Php::ByVal("text", Php::Type::String, true)});
        
        lineEdit.method<&LineEdit::setValidator>("setValidator", {Php::ByVal("validator", Php::Type::Object, true)});
        lineEdit.method<&LineEdit::text>("text");

        // signals
        lineEdit.method<&LineEdit::textChanged>("textChanged", {Php::ByVal("callback", Php::Type::Callable)});
        lineEdit.method<&LineEdit::textEdited>("textEdited", {Php::ByVal("callback", Php::Type::Callable)});

        return lineEdit;
    }
};


#endif //PHPQT_LINEEDIT_H
