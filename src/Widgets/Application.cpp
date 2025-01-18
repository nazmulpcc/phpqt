#include <phpcpp.h>
#include "application.h"
#include <iostream>

void Application::__construct()
{
    int argc = 1;
    // without one argument, QApplication crashes randomly, specially for webengine.
    char *argv[] = {(char *)"phpqt"};
    this->native = new QApplication(argc, argv);
}

Php::Value Application::exec()
{
    return {QApplication::exec()};
}

void Application::quit()
{
    this->native->quit();
}
