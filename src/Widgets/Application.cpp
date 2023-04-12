#include <phpcpp.h>
#include "application.h"

void Application::__construct(Php::Parameters &params)
{
    int argc = 0;
    char *argv[] = {};
    if (params.size() > 0) {
        argc = params[0].numericValue();
    }
    if (params.size() > 1){
        for (int i = 0; i < params[1].size(); i++)
        {
            // todo: fix arg passing
            //argv[i] = Php::Value(params[1][i]).stringValue().c_str();
        }
    }
    
    this->native = new QApplication(argc, argv);
}

Php::Value Application::exec()
{
    return this->native->exec();
}