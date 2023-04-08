#include "Object.h"
#include <iostream>

Object::Object(){}

Object::Object(QObject *n)
{
    this->setNative(n);
}

void Object::setNative(QObject *n)
{
    this->native = n;
}

QObject *Object::getNative()
{
    return this->native;
}

void Object::blockSignals(Php::Parameters &params)
{
    this->native->blockSignals(params[0].boolValue());
}

void Object::dumpObjectInfo()
{
    this->native->dumpObjectInfo();
}

void Object::dumpObjectTree()
{
    this->native->dumpObjectTree();
}

Php::Value Object::dynamicPropertyNames()
{
    return Php::Value("TODO:: implement QList");
}

Php::Value Object::isWidgetType()
{
    return Php::Value(this->native->isWidgetType());
}

Php::Value Object::isWindowType()
{
    return Php::Value(this->native->isWindowType());
}

void Object::killTimer(Php::Parameters &params)
{
    this->native->killTimer(params[0].numericValue());
}

Php::Value Object::parent()
{
    return Php::Value(0);
}

Php::Value Object::objectName()
{
    return Php::Value(this->native->objectName().toStdString());
}

void Object::setObjectName(Php::Parameters &params)
{
    this->native->setObjectName(QString::fromStdString(params[0].stringValue()));
}

void Object::setParent(Php::Parameters &params)
{
    auto parent = params[0].implementation<Object>();
    this->native->setParent(parent->getNative());
}

Php::Value Object::startTimer(Php::Parameters &params)
{
    int fd = this->native->startTimer(params[0].numericValue());
    return Php::Value(fd);
}
