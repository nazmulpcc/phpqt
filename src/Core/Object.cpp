#include "Object.h"
#include <iostream>
#include "TimerObject.h"
#include "Thread.h"

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

void Object::__construct(Php::Parameters &params)
{
    QObject *parent = nullptr;
    if (params.size() > 0) {
        parent = params[0].implementation<Object>()->getNative();
    }
    this->setNative(new QObject(parent));
}

void Object::blockSignals(Php::Parameters &params)
{
    this->native->blockSignals(params[0].boolValue());
}

void Object::onObjectNameChanged(Php::Parameters &params)
{
    auto callback = params[0];

    this->native->connect(this->native, &QObject::objectNameChanged, [callback](QString objectName){
        callback(Php::Value(objectName.toStdString()));
    });
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
    int fd = params[0].numericValue();
    this->timers[fd]->killTimer(fd);
    delete this->timers[fd]; // does this actually free memory? Or is there a possibility of memory leak?
    this->timers.erase(fd);
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

Php::Value Object::thread()
{
    auto thread = this->native->thread();
    auto phpThread = new Thread;
    phpThread->setNative(thread);
    return Php::Object(Thread::CLASSPATH.c_str(), phpThread);
}

void Object::setParent(Php::Parameters &params)
{
    auto parent = params[0].implementation<Object>();
    this->native->setParent(parent->getNative());
}

void Object::moveToThread(Php::Parameters &params)
{
    auto thread = params[0].implementation<Thread>();
    this->native->moveToThread(thread->getNative());
}

Php::Value Object::startTimer(Php::Parameters &params)
{
    Php::Value callback;
    Qt::TimerType type;
    if (params.size() == 2) {
        callback = params[1];
        type = Qt::CoarseTimer;
    }else{
        auto callback = params[2];
        auto type = static_cast<Qt::TimerType>(params[1].numericValue());
    }
    
    TimerObject *timerObject = new TimerObject(this->native);
    int fd = timerObject->start(params[0].numericValue(), type, callback);

    this->timers[fd] = timerObject;

    return Php::Value(fd);
}
