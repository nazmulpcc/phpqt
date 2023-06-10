#ifndef BOXLAYOUT_H
#define BOXLAYOUT_H

#include "Layout.h"
#include <phpcpp.h>
#include <QtWidgets/QBoxLayout>

class BoxLayout : public Layout
{
private:
    QBoxLayout *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\BoxLayout";

    QBoxLayout *getNative();
    void setNative(QBoxLayout *n);

    void __construct(Php::Parameters &params);
    void addLayout(Php::Parameters &params);
    void addSpacerItem(Php::Parameters &params);
    void addSpacing(Php::Parameters &params);
    void addStretch(Php::Parameters &params);
    void addStrut(Php::Parameters &params);
    void addWidget(Php::Parameters &params);
    Php::Value direction();
    void insertItem(Php::Parameters &params);
    void insertLayout(Php::Parameters &params);
    void insertSpacerItem(Php::Parameters &params);
    void insertSpacing(Php::Parameters &params);
    void insertStretch(Php::Parameters &params);
    void insertWidget(Php::Parameters &params);
    void setDirection(Php::Parameters &params);
    void setSpacing(Php::Parameters &params);
    void setStretch(Php::Parameters &params);
    void setStretchFactor(Php::Parameters &params);
    Php::Value spacing();
    Php::Value stretch(Php::Parameters &params);

    static Php::Class<BoxLayout> _DEFINITION()
    {
        Php::Class<BoxLayout>definition(BoxLayout::CLASSPATH.c_str());

        definition.method<&BoxLayout::__construct>("__construct", {
            Php::ByVal("direction", Php::Type::Numeric, true),
            Php::ByVal("parent", Php::Type::Object, false)
        });
        definition.method<&BoxLayout::addLayout>("addLayout", {
            Php::ByRef("layout", Php::Type::Object, true),
            Php::ByRef("stretch", Php::Type::Numeric, false)
        });
        definition.method<&BoxLayout::addSpacerItem>("addSpacerItem", {
            Php::ByRef("spacerItem", Php::Type::Object, true)
        });
        definition.method<&BoxLayout::addSpacing>("addSpacing", {Php::ByVal("size", Php::Type::Numeric, true)});
        definition.method<&BoxLayout::addStretch>("addStretch", {Php::ByVal("stretch", Php::Type::Numeric, false)});
        definition.method<&BoxLayout::addStrut>("addStrut", {Php::ByVal("size", Php::Type::Numeric, true)});
        definition.method<&BoxLayout::addWidget>("addWidget", {
            Php::ByRef("widget", Php::Type::Object, true),
            Php::ByVal("stretch", Php::Type::Numeric, false),
            Php::ByVal("alignment", Php::Type::Numeric, false),
        });
        definition.method<&BoxLayout::direction>("direction");
        definition.method<&BoxLayout::insertItem>("insertItem", {
            Php::ByVal("index", Php::Type::Numeric, true),
            Php::ByRef("item", Php::Type::Object, true)
        });
        definition.method<&BoxLayout::insertLayout>("insertLayout", {
            Php::ByVal("index", Php::Type::Numeric, true),
            Php::ByRef("layout", Php::Type::Object, true),
            Php::ByVal("stretch", Php::Type::Numeric, false)
        });
        definition.method<&BoxLayout::insertSpacerItem>("insertSpacerItem", {
            Php::ByVal("index", Php::Type::Numeric, true),
            Php::ByRef("spacerItem", Php::Type::Object, true)
        });
        definition.method<&BoxLayout::insertSpacing>("insertSpacing", {
            Php::ByVal("index", Php::Type::Numeric, true),
            Php::ByVal("size", Php::Type::Numeric, true)
        });
        definition.method<&BoxLayout::insertStretch>("insertStretch", {
            Php::ByVal("index", Php::Type::Numeric, true),
            Php::ByVal("size", Php::Type::Numeric, true)
        });
        definition.method<&BoxLayout::insertWidget>("insertWidget", {
            Php::ByVal("index", Php::Type::Numeric, true),
            Php::ByRef("widget", Php::Type::Object, true),
            Php::ByVal("stretch", Php::Type::Numeric, false),
            Php::ByVal("alignment", Php::Type::Numeric, false)
        });
        definition.method<&BoxLayout::setDirection>("setDirection", {Php::ByVal("direction", Php::Type::Numeric, true)});
        definition.method<&BoxLayout::setSpacing>("setSpacing", {Php::ByVal("spacing", Php::Type::Numeric, true)});
        definition.method<&BoxLayout::setStretch>("setStretch", {Php::ByVal("stretch", Php::Type::Numeric, true)});
        definition.method<&BoxLayout::setStretchFactor>("setStretchFactor", {
            Php::ByRef("widget", Php::Type::Numeric, true),
            Php::ByVal("stretch", Php::Type::Numeric, true)
        });
        definition.method<&BoxLayout::spacing>("spacing");
        definition.method<&BoxLayout::stretch>("stretch", {Php::ByVal("index", Php::Type::Numeric, true)});

        return definition;
    }
};


#endif
