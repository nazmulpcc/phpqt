#include<phpcpp.h>
#include "mainwindow.h"
#include "label.h"
#include <QtWidgets/QWidget>
#include <iostream>
#include <QtWidgets/QPushButton>
#include "../macros.h"

void MainWindow::__construct()
{
    this->setNative(new QMainWindow);
    this->mainWindow = dynamic_cast<QMainWindow *>(this->native);
}

void MainWindow::setCentralWidget(Php::Parameters &params)
{
    Php::Value param = params[0];
    Label* widget = (Label *)param.implementation();

    if (nullptr == widget || nullptr == widget->getNative())
    {
        Php::out << "found null" << std::endl;
    }

    this->mainWindow->setCentralWidget(widget->getNative());
}

FORWARD_CALL(MainWindow, Widget, show)