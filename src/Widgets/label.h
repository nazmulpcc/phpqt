#include "widget.h"
#include<phpcpp.h>
#include <QtWidgets/QLabel>

class Label : public Widget
{
private:
    QLabel* native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\Label";

    void __construct(Php::Parameters &params);
    void setAlignment(Php::Parameters &params);
    void setText(Php::Parameters &params);

    static Php::Class<Label> _DEFINITION()
    {
        Php::Class<Label> label(Label::CLASSPATH.c_str());
        label.method<&Label::__construct>("__construct", {
            Php::ByVal("text", Php::Type::String, false)
        });
        label.method<&Label::setAlignment>("setAlignment", {Php::ByVal("alignment", Php::Type::Numeric, false)});
        label.method<&Label::setText>("setText", {Php::ByVal("text", Php::Type::String, false)});

        return label;
    }
};