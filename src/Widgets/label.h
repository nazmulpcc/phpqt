#include "widget.h"
#include<phpcpp.h>
#include <QtWidgets/QLabel>

class Label : public Widget
{
private:
    QLabel* label;

public:
    void __construct(Php::Parameters &params);
    void setText(Php::Parameters &params);

    static Php::Class<Label> _DEFINITION()
    {
        Php::Class<Label> label("Qt\\Widgets\\Label");
        label.method<&Label::__construct>("__construct", {
            Php::ByVal("text", Php::Type::String, false)
        });
        label.method<&Label::setText>("setText", {Php::ByVal("text", Php::Type::String, false)});

        return label;
    }
};