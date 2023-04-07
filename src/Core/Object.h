#ifndef OBJECT_H
#define OBJECT_H

#include "phpcpp.h"
#include <QtCore/QObject>

class Object: public Php::Base
{
private:
    QObject *native;

public:
    Object();
    Object(QObject *n);

    virtual void setNative(QObject *n);
    virtual QObject *getNative();

    void setObjectName(Php::Parameters &params);

    static Php::Class<Object> _DEFINITION()
    {
        Php::Class<Object> definition("Qt\\Core\\Obj");

        definition.method<&Object::setObjectName>("setObjectName", {
            Php::ByVal("name", Php::Type::String, true)
        });

        return definition;
    }
};

#endif