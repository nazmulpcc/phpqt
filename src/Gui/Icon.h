#ifndef ICON_H
#define ICON_H

#include<phpcpp.h>
#include<QtGui/QIcon>

class Icon : public Php::Base
{
private:
    QIcon *native;
public:
    inline static const char *CLASSPATH = "Qt\\Gui\\Icon";

    QIcon *getNative();
    void setNative(QIcon *n);

    void __construct(Php::Parameters &params);

    static Php::Class<Icon> _DEFINITION()
    {
        Php::Class<Icon>definition(Icon::CLASSPATH);

        definition.method<&Icon::__construct>("__construct", {
            Php::ByRef("file", Php::Type::Object, true)
        });
    }
};

#endif
