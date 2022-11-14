#include <phpcpp.h>
#include "application.h"

void Application::__construct()
{
    int argc = 0;
    char *argv[] = {};
    this->native = new QApplication(argc, argv);
}

Php::Value Application::exec()
{
    return this->native->exec();
}