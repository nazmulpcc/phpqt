#include <phpcpp.h>
#include <iostream>
#include "TimerObject.h"
#include "TimerEvent.h"
#include <QtCore/QObject>

TimerObject::TimerObject(QObject *parent): QObject(parent)
{
}

TimerObject::~TimerObject()
{
    Php::out << "Destroying a timeobject\n";
}

int TimerObject::start(int time, Qt::TimerType type, Php::Value c)
{
    this->callback = c;

    return this->startTimer(time, type);
}

void TimerObject::timerEvent(QTimerEvent *event)
{
    auto *phpEvent = new TimerEvent;
    phpEvent->setNative(event);
    callback(Php::Object(TimerEvent::CLASSPATH.c_str(), phpEvent));
}