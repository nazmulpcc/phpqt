#include<phpcpp.h>
#include "mainwindow.h"
#include "label.h"
#include "widget.h"
#include <QtWidgets/QWidget>
#include <iostream>
#include <QtWidgets/QPushButton>

void MainWindow::__construct()
{
    this->native = new QMainWindow;
    QPushButton button("&Testing", this->native);
}

// void MainWindow::addToolBar(Php::Parameters &params)
// {
//     QString title = QString::fromStdString((std::string) params[0]);

//     this->native->addToolBar(title);
// }

void MainWindow::setCentralWidget(Php::Parameters &params)
{
    Php::Value param = params[0];
    Label* widget = (Label *)param.implementation();

    if (nullptr == widget || nullptr == widget->getNative())
    {
        Php::out << "found null" << std::endl;
    }
    
    this->native->setCentralWidget(widget->getNative());
}

void MainWindow::show()
{
    this->native->show();
}