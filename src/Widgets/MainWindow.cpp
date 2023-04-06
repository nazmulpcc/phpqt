#include<phpcpp.h>
#include "mainwindow.h"
#include "widget.h"
#include <iostream>

void MainWindow::__construct()
{
    this->native = new QMainWindow;
    setNative(this->native);
}

void MainWindow::setCentralWidget(Php::Parameters &params)
{
    Php::Value param = params[0];
    Widget* widget = (Widget *)param.implementation();

    if (nullptr == widget || nullptr == widget->getNative())
    {
        Php::out << "found null" << std::endl;
    }

    this->native->setCentralWidget(widget->getNative());
}
