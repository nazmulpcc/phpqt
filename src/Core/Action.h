#ifndef ACTION_H
#define ACTION_H

#include "../Core/Object.h"
#include <phpcpp.h>
#include <QAction>

class Action : public Object
{
private:
    QAction *native;

public:
    inline static const char *CLASSPATH = "Qt\\Core\\Action";

    QAction *getNative();
    void setNative(QAction *n);
    void __construct(Php::Parameters &params);

    static Php::Class<Action> _DEFINITION()
    {
        Php::Class<Action>definition(Action::CLASSPATH);

        definition.method<&Action::__construct>("__construct", {
            Php::ByRef("icon", Php::Type::Object, true),
            Php::ByRef("text", Php::Type::Object, false),
            Php::ByRef("parent", Php::Type::Object, false)
        });

        return definition;
    }
};

#endif
