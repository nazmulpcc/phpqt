#include <phpcpp.h>
#include "pushbutton.h"
#include "widget.h"
#include "mainwindow.h"

void PushButton::__construct(Php::Parameters &params)
{
    QString name = QString::fromStdString((std::string)params[0]);
    MainWindow *parent = (MainWindow *) params[1].implementation();

    this->native = new QPushButton(name, parent->getNative());
}

void PushButton::onPressed(Php::Parameters &params)
{
    //
}