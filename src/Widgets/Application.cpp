#include <phpcpp.h>
#include "application.h"
#include <iostream>

void Application::__construct()
{
    int argc = 0;
    char *argv[] = {};
    Php::out << "Before app\n";
    this->native = new QApplication(argc, argv);
    Php::out << "After app\n";
}

Php::Value Application::exec()
{
    return {QApplication::exec()};
}