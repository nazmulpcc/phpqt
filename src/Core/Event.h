#ifndef EVENT_H
#define EVENT_H
#include <phpcpp.h>
#include <QtCore/QEvent>

class Event : public Php::Base
{
private:
    QEvent *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Core\\Event";

    void setNative(QEvent *n);
    QEvent *getNative();

    void __construct(Php::Parameters &params);
    void accept();
    void ignore();
    Php::Value isAccepted();
    void setAccepted(Php::Parameters &params);
    Php::Value spontaneous();
    Php::Value type();

    static Php::Class<Event> _DEFINITION()
    {
        Php::Class<Event>definition(Event::CLASSPATH.c_str());

        definition.method<&Event::__construct>("__construct", {
            Php::ByVal("type", Php::Type::Numeric, true)
        });
        definition.method<&Event::accept>("accept");
        definition.method<&Event::ignore>("ignore");
        definition.method<&Event::isAccepted>("isAccepted");
        definition.method<&Event::setAccepted>("setAccepted", {
            Php::ByVal("accepted", Php::Type::Bool, true)
        });
        definition.method<&Event::spontaneous>("spontaneous");
        definition.method<&Event::type>("type");

        return definition;
    }
};

#endif
