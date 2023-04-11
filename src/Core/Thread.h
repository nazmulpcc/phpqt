#ifndef THREAD_H
#define THREAD_H

#include <phpcpp.h>
#include "Object.h"
#include <QtCore/QThread>

class Thread : public Object
{
private:
    QThread *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Core\\Thread";

    void setNative(QThread *n);
    QThread *getNative();

    void __construct(Php::Parameters &params);
    void exit(Php::Parameters &params);
    Php::Value isFinished();
    Php::Value isInterruptionRequested();
    Php::Value isRunning();
    Php::Value loopLevel();
    Php::Value priority();
    void requestInterruption();
    void setEventDispatcher(Php::Parameters &params);
    void setPriority(Php::Parameters &params);
    void setStackSize(Php::Parameters &params);
    Php::Value stackSize();
    Php::Value wait(Php::Parameters &params);

    void onFinished(Php::Parameters &params);
    void onStarted(Php::Parameters &params);

    void quit();
    void start(Php::Parameters &params);
    void terminate();

    static Php::Class<Thread> _DEFINITION() {
        Php::Class<Thread> definition(Thread::CLASSPATH.c_str());

        definition.constant("IdlePriority", 0);
        definition.constant("LowestPriority", 1);
        definition.constant("LowPriority", 2);
        definition.constant("NormalPriority", 3);
        definition.constant("HighPriority", 4);
        definition.constant("HighestPriority", 5);
        definition.constant("TimeCriticalPriority", 6);
        definition.constant("InheritPriority", 7);

        definition.method<&Thread::__construct>("__construct", {
            Php::ByRef("parent", Php::Type::Object, false)
        });
        definition.method<&Thread::exit>("exit", { Php::ByVal("returnCode", Php::Type::Numeric, true) });
        definition.method<&Thread::isFinished>("isFinished");
        definition.method<&Thread::isInterruptionRequested>("isInterruptionRequested");
        definition.method<&Thread::isRunning>("isRunning");
        definition.method<&Thread::loopLevel>("loopLevel");
        definition.method<&Thread::priority>("priority");
        definition.method<&Thread::requestInterruption>("requestInterruption");
        definition.method<&Thread::setEventDispatcher>("setEventDispatcher", {Php::ByRef("eventDispatcher", Php::Type::Object, true)});
        definition.method<&Thread::setPriority>("setPriority", {Php::ByVal("priority", Php::Type::Numeric, true)});
        definition.method<&Thread::setStackSize>("setStackSize", {Php::ByVal("stackSize", Php::Type::Numeric, true)});
        definition.method<&Thread::stackSize>("stackSize");
        definition.method<&Thread::wait>("wait", {Php::ByVal("time", Php::Type::Numeric, true)});

        definition.method<&Thread::onFinished>("onFinished", { Php::ByVal("callback", Php::Type::Callable, true) });
        definition.method<&Thread::onStarted>("onStarted", { Php::ByVal("callback", Php::Type::Callable, true) });

        definition.method<&Thread::quit>("quit");
        definition.method<&Thread::start>("start", {Php::ByVal("priority", Php::Type::Numeric, false)});
        definition.method<&Thread::terminate>("terminate");
        
        return definition;
    }
};

#endif
