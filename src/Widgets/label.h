#include<phpcpp.h>
#include <QtWidgets/QLabel>
#include "widget.h"

class Label : public Widget
{
private:
    QLabel *native;

public:
    void __construct(Php::Parameters &params);
    void show();
    void setText(Php::Parameters &params);
    QLabel* getNative();

    static Php::Class<Label> _DEFINITION()
    {
        Php::Class<Label> label("Qt\\Widgets\\Label");
        label.method<&Label::__construct>("__construct", {
            Php::ByVal("text", Php::Type::String, false)
        });
        label.method<&Label::setText>("setText", {Php::ByVal("text", Php::Type::String, false)});
        label.method<&Label::show>("show");

        return label;
    }
};