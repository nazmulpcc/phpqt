#include "Object.h"
#include <QtCore/QObject>
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

void Object::setObjectName(Php::Parameters &params)
{
    this->native->setObjectName(QString::fromStdString(params[0].stringValue()));
}