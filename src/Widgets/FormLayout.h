#include "Layout.h"
#include <QtWidgets/QFormLayout>

class FormLayout : public Layout
{
private:
    QFormLayout *native;

public:
    void __construct(Php::Parameters &params);
    void addRow(Php::Parameters &params);

    static Php::Class<FormLayout> _DEFINITION()
    {
        Php::Class<FormLayout> definition("Qt\\Widgets\\FormLayout");

        definition.method<&FormLayout::__construct>("__construct");
        definition.method<&FormLayout::addRow>("addRow", {
            Php::ByVal("label", Php::Type::Object, true),
            Php::ByVal("parent", Php::Type::Object, false)
        });

        return definition;
    }
};
