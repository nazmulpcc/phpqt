#ifndef TIMEROBJECT_H
#define TIMEROBJECT_H

#include<phpcpp.h>
#include<QtCore/QObject>
#include<QtCore/QTimerEvent>

class TimerObject: public QObject
{
public:
    TimerObject(QObject *parent = nullptr);

    int start(int time, Qt::TimerType type, Php::Value c);

protected:
    Php::Value callback;
    void timerEvent(QTimerEvent *event) override;
};

#endif
