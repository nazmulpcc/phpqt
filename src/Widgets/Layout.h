#ifndef LAYOUT_H
#define LAYOUT_H

#include "../Core/Object.h"
#include <phpcpp.h>
#include <QtWidgets/QLayout>

/*
 * TODO: Replace the native QLayout with a custom class that extends QLayout
 * This will enable extending the PHP Layout class, and setting some custom logic
 * See more at here: https://doc.qt.io/qt-5/qlayout.html#details
 */
class Layout : public Object
{
private:
    QLayout *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\Layout";

    QLayout *getNative();
    void setNative(QLayout *n);

    Php::Value activate();
    void addWidget(Php::Parameters &params);
    Php::Value getContentsMargins(Php::Parameters &params);
    Php::Value isEnabled();
    Php::Value menuBar();
    Php::Value parentWidget();
    void removeItem(Php::Parameters &params);
    void removeWidget(Php::Parameters &params);
    Php::Value setAlignment(Php::Parameters &params);
    void setContentsMargins(Php::Parameters &params);
    void setEnabled(Php::Parameters &params);
    void setMenuBar(Php::Parameters &params);
    void setSizeConstraint(Php::Parameters &params);
    void setSpacing(Php::Parameters &params);
    Php::Value sizeConstraint();
    Php::Value spacing();
    void update();

    static Php::Class<Layout> _DEFINITION()
    {
        Php::Class<Layout> definition(Layout::CLASSPATH.c_str(), Php::Abstract);

        definition.method<&Layout::activate>("activate");
        // definition.method<&Layout::addWidget>("addWidget", {Php::ByRef("parent", Php::Type::Object, false)});
        definition.method<&Layout::getContentsMargins>("getContentsMargins", {
            Php::ByRef("left", Php::Type::Numeric, false),
            Php::ByRef("top", Php::Type::Numeric, false),
            Php::ByRef("right", Php::Type::Numeric, false),
            Php::ByRef("bottom", Php::Type::Numeric, false)
        });
        definition.method<&Layout::isEnabled>("isEnabled");
        definition.method<&Layout::menuBar>("menuBar");
        definition.method<&Layout::parentWidget>("parentWidget");
        definition.method<&Layout::removeItem>("removeItem", {Php::ByRef("item", Php::Type::Object, true)});
        definition.method<&Layout::removeWidget>("removeWidget", {Php::ByRef("item", Php::Type::Object, true)});
        definition.method<&Layout::setAlignment>("setAlignment", {
            Php::ByRef("widget", Php::Type::Object, true),
            Php::ByRef("alignment", Php::Type::Numeric, true),
        });
        definition.method<&Layout::setContentsMargins>("setContentsMargins", {
            Php::ByVal("left", Php::Type::Numeric, true),
            Php::ByVal("top", Php::Type::Numeric, true),
            Php::ByVal("right", Php::Type::Numeric, true),
            Php::ByVal("bottom", Php::Type::Numeric, true)
        });
        definition.method<&Layout::setEnabled>("setEnabled", { Php::ByVal("enabled", Php::Type::Bool, true) });
        definition.method<&Layout::setMenuBar>("setMenuBar", { Php::ByVal("menu", Php::Type::Object, true) });
        definition.method<&Layout::setSizeConstraint>("setSizeConstraint", { Php::ByVal("constraint", Php::Type::Numeric, true) });
        definition.method<&Layout::setSpacing>("setSpacing", { Php::ByVal("space", Php::Type::Numeric, true) });
        definition.method<&Layout::sizeConstraint>("sizeConstraint");
        definition.method<&Layout::spacing>("spacing");
        definition.method<&Layout::update>("update");

        return definition;
    }
};

#endif
