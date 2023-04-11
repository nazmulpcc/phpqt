#include "Object.h"
#include "Thread.h"
#include <QtCore/QObject>

void Thread::setNative(QThread *n)
{
    this->native = n;
    Object::setNative(n);
}

QThread *Thread::getNative()
{
    return this->native;
}

void Thread::__construct(Php::Parameters &params)
{
    QObject *parent = nullptr;
    if (params.size() > 0) {
        parent = params[0].implementation<Object>()->getNative();
    }

    this->setNative(new QThread(parent));
}

void Thread::exit(Php::Parameters &params)
{
    this->native->exit();
}

Php::Value Thread::isFinished()
{
    return Php::Value(this->native->isFinished());
}

Php::Value Thread::isInterruptionRequested()
{
    return Php::Value(this->native->isInterruptionRequested());
}

Php::Value Thread::isRunning()
{
    return Php::Value(this->native->isRunning());
}

Php::Value Thread::loopLevel()
{
    return Php::Value(this->native->loopLevel());
}

Php::Value Thread::priority()
{
    return Php::Value(this->native->priority());
}

void Thread::requestInterruption()
{
    this->native->requestInterruption();
}

void Thread::setEventDispatcher(Php::Parameters &params)
{
    // TODO: implement QAbstractEventDispatcher
}

void Thread::setPriority(Php::Parameters &params)
{
    QThread::Priority priority = static_cast<QThread::Priority>(params[0].numericValue());
    this->native->setPriority(priority);
}

void Thread::setStackSize(Php::Parameters &params)
{
    this->native->setStackSize(params[0].numericValue());
}

Php::Value Thread::stackSize()
{
    return Php::Value((int64_t) this->native->stackSize());
}

Php::Value Thread::wait(Php::Parameters &params)
{
    return Php::Value(this->native->wait());
}

void Thread::onFinished(Php::Parameters &params)
{
    auto callable = params[0];
    this->native->connect(this->native, &QThread::finished, [callable]{
        callable();
    });
}

void Thread::onStarted(Php::Parameters &params)
{
    auto callable = params[0];
    this->native->connect(this->native, &QThread::started, [callable]{
        callable();
    });
}

void Thread::quit()
{
    this->native->quit();
}

void Thread::start(Php::Parameters &params)
{
    auto priority = QThread::InheritPriority;
    if (params.size() > 0) {
        priority = static_cast<QThread::Priority>(params[0].numericValue());
    }
    
    this->native->start(priority);
}

void Thread::terminate()
{
    this->native->terminate();
}
