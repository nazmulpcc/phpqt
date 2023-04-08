#ifndef LAYOUT_H
#define LAYOUT_H

#include "../Core/Object.h"
#include <phpcpp.h>
#include <QtWidgets/QLayout>

class Layout : public Object
{
private:
    QLayout *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\Layout";

    QLayout *getNative();
    void setNative(QLayout *n);

    static Php::Class<Layout> _DEFINITION()
    {
        Php::Class<Layout> definition(Layout::CLASSPATH.c_str());

        return definition;
    }
};

#endif
