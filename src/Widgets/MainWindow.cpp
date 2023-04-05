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

void MainWindow::setWindowTitle(Php::Parameters &params) {
    this->mainWindow->setWindowTitle(QString::fromStdString(params[0].stringValue()));
}

FORWARD_CALL_WITH_PARAMS(MainWindow, Widget, setGeometry)

FORWARD_CALL(MainWindow, Widget, show)