#include<phpcpp.h>
#include "mainwindow.h"
#include "widget.h"
#include <iostream>

void MainWindow::__construct()
{
    this->setNative(new QMainWindow);
    this->mainWindow = dynamic_cast<QMainWindow *>(this->native);
}

void MainWindow::setCentralWidget(Php::Parameters &params)
{
    Php::Value param = params[0];
    Widget* widget = (Widget *)param.implementation();

    if (nullptr == widget || nullptr == widget->getNative())
    {
        Php::out << "found null" << std::endl;
    }

    this->mainWindow->setCentralWidget(widget->getNative());
}
