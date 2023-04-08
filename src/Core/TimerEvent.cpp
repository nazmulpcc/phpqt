#include "TimerEvent.h"

void TimerEvent::__construct(Php::Parameters &params)
{
    this->native = new QTimerEvent(params[0].numericValue());
    Event::setNative(this->native);
}

Php::Value TimerEvent::timerId()
{
    return Php::Value(this->native->timerId());
}
