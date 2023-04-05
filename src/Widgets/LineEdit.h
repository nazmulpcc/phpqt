#ifndef PHPQT_LINEEDIT_H
#define PHPQT_LINEEDIT_H

#include "widget.h"
#include<phpcpp.h>

class LineEdit : public Widget {
    void __construct(Php::Parameters &params);
    Php::Value placeholderText();
    void setPlaceholderText(Php::Parameters &params);

    static Php::Class<LineEdit> _DEFINITION()
    {
        Php::Class<LineEdit> lineEdit("Qt\\Widgets\\LineEdit");
        lineEdit.method<&LineEdit::__construct>("__construct", {
                Php::ByVal("text", Php::Type::String, false)
        });

        return lineEdit;
    }
};


#endif //PHPQT_LINEEDIT_H
