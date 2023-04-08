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

    inline static const std::string CLASSPATH = "Qt\\Core\\Obj";

    virtual void setNative(QObject *n);
    virtual QObject *getNative();

    void blockSignals(Php::Parameters &params);
    void dumpObjectInfo();
    void dumpObjectTree();
    Php::Value dynamicPropertyNames();
    Php::Value isWidgetType();
    Php::Value isWindowType();
    void killTimer(Php::Parameters &params);
    Php::Value parent();
    Php::Value objectName();
    void setObjectName(Php::Parameters &params);
    void setParent(Php::Parameters &params);
    Php::Value startTimer(Php::Parameters &params);

    static Php::Class<Object> _DEFINITION()
    {
        Php::Class<Object> definition(Object::CLASSPATH.c_str());

        definition.method<&Object::blockSignals>("blockSignals", {
            Php::ByVal("block", Php::Type::Bool, true)
        });
        definition.method<&Object::dumpObjectInfo>("dumpObjectInfo");
        definition.method<&Object::dumpObjectTree>("dumpObjectTree");
        definition.method<&Object::isWidgetType>("isWidgetType");
        definition.method<&Object::isWindowType>("isWindowType");
        definition.method<&Object::killTimer>("killTimer", {
            Php::ByVal("fd", Php::Type::Numeric, true)
        });
        definition.method<&Object::objectName>("objectName");
        definition.method<&Object::parent>("parent");
        definition.method<&Object::setObjectName>("setObjectName", {
            Php::ByVal("name", Php::Type::String, true)
        });
        definition.method<&Object::setParent>("setParent", {
            Php::ByRef("parent", Php::Type::Object, true)
        });
        definition.method<&Object::startTimer>("startTimer", {
            Php::ByVal("interval", Php::Type::Numeric, true),
            Php::ByVal("timerType", Php::Type::Numeric, true)
        });

        return definition;
    }
};

#endif