#include "TimerEvent.h"

void TimerEvent::setNative(QTimerEvent *n)
{
    this->native = n;
    Event::setNative(this->native);
}

QTimerEvent *TimerEvent::getNative()
{
    return this->native;
}

void TimerEvent::__construct(Php::Parameters &params)
{
    this->native = new QTimerEvent(params[0].numericValue());
    Event::setNative(this->native);
}

Php::Value TimerEvent::timerId()
{
    return Php::Value(this->native->timerId());
}
