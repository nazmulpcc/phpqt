#ifndef SIZE_H
#define SIZE_H

#include<phpcpp.h>
#include<QtCore/QSize>

class Size : public Php::Base
{
private:
    QSize *native;

public:
    inline static const char *CLASSPATH = "Qt\\Core\\Size";

    Size() = default;
    Size(int width , int height);
    Size(QSize *n);

    QSize *getNative() const;
    void setNative(QSize *n);

    void __construct(Php::Parameters &params);
    int __compare(const Size &other) const;

    Php::Value boundedTo(Php::Parameters &params) const;
    Php::Value expandedTo(Php::Parameters &params) const;
    Php::Value grownBy(Php::Parameters &params) const;
    Php::Value height() const;
    Php::Value isEmpty() const;
    Php::Value isNull() const;
    Php::Value isValid() const;
    void scale(Php::Parameters &params);
    Php::Value scaled(Php::Parameters &params);
    void setHeight(Php::Parameters &params);
    void setWidth(Php::Parameters &params);
    Php::Value shrunkBy(Php::Parameters &params) const;
    void transpose();
    Php::Value transposed() const;
    Php::Value width() const;

    static Php::Class<Size> _DEFINITION()
    {
        Php::Class<Size>definition(Size::CLASSPATH);

        // TODO: property doesn't show up in PHP
        definition.property("width", &Size::width);
        definition.property("height", &Size::height);

        definition.method<&Size::__construct>("__construct", {
            Php::ByVal("width", Php::Type::Numeric, false),
            Php::ByVal("height", Php::Type::Numeric, false)
        });

        definition.method<&Size::boundedTo>("boundedTo", {Php::ByVal("otherSize", Php::Type::Object, true)});
        definition.method<&Size::expandedTo>("expandedTo", {Php::ByVal("otherSize", Php::Type::Object, true)});
        definition.method<&Size::grownBy>("grownBy", {Php::ByVal("margins", Php::Type::Object, true)});
        definition.method<&Size::height>("height");
        definition.method<&Size::isEmpty>("isEmpty");
        definition.method<&Size::isNull>("isNull");
        definition.method<&Size::isValid>("isValid");
        definition.method<&Size::scale>("scale", {
            Php::ByVal("width", Php::Type::Object, true),
            Php::ByVal("height", Php::Type::Object, true),
            Php::ByVal("mode", Php::Type::Object, false),
        });
        definition.method<&Size::scaled>("scaled", {
            Php::ByVal("width", Php::Type::Object, true),
            Php::ByVal("height", Php::Type::Object, true),
            Php::ByVal("mode", Php::Type::Object, false),
        });
        definition.method<&Size::setHeight>("setHeight", {Php::ByVal("height", Php::Type::Numeric, true)});
        definition.method<&Size::setWidth>("setWidth", {Php::ByVal("width", Php::Type::Numeric, true)});
        definition.method<&Size::shrunkBy>("shrunkBy", {Php::ByVal("margins", Php::Type::Object, true)});
        definition.method<&Size::transpose>("transpose");
        definition.method<&Size::transposed>("transposed");
        definition.method<&Size::width>("width");

        return definition;
    }
};

#endif
