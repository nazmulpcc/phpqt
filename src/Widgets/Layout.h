#ifndef LAYOUT_H
#define LAYOUT_H

#include <phpcpp.h>
#include <QtWidgets/QLayout>

class Layout : public Php::Base
{
private:
    QLayout *native;

public:
    QLayout *getNative();
    void setNative(QLayout *n);

    static Php::Class<Layout> _DEFINITION()
    {
        Php::Class<Layout> definition("Qt\\Widgets\\Layout");

        return definition;
    }
};

#endif
