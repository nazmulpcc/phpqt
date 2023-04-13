#include "widget.h"
#include<phpcpp.h>
#include <QtWidgets/QLabel>
#include <QtGui/QPixmap>

class Label : public Widget
{
private:
    QLabel* native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\Label";

    void __construct(Php::Parameters &params);
    Php::Value pixmap();
    void setAlignment(Php::Parameters &params);
    void setPixmap(Php::Parameters &params);
    void setText(Php::Parameters &params);

    static Php::Class<Label> _DEFINITION()
    {
        Php::Class<Label> definition(Label::CLASSPATH.c_str());
        definition.method<&Label::__construct>("__construct", {
            Php::ByVal("text", Php::Type::String, false)
        });

        definition.method<&Label::pixmap>("pixmap");
        definition.method<&Label::setAlignment>("setAlignment", {Php::ByVal("alignment", Php::Type::Numeric, false)});
        definition.method<&Label::setPixmap>("setPixmap", {Php::ByRef("pixmap", Php::Type::Object, true)});
        definition.method<&Label::setText>("setText", {Php::ByVal("text", Php::Type::String, false)});

        return definition;
    }
};