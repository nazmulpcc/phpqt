#ifndef TIMEREVENT_H
#define TIMEREVENT_H

#include "Event.h"
#include<phpcpp.h>
#include<QtCore/QTimerEvent>

class TimerEvent : public Event
{
private:
    QTimerEvent *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Core\\TimerEvent";

    void __construct(Php::Parameters &params);
    Php::Value timerId();

    static Php::Class<TimerEvent> _DEFINITION()
    {
        Php::Class<TimerEvent> definition(TimerEvent::CLASSPATH.c_str());

        definition.method<&TimerEvent::__construct>("__construct", {
            Php::ByVal("timerId", Php::Type::Numeric, true)
        });
        definition.method<&TimerEvent::timerId>("timerId");

        return definition;
    }
};

#endif