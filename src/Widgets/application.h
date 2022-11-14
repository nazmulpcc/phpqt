#include<phpcpp.h>
#include<QtWidgets/QApplication>

class Application : public Php::Base 
{
private:
    QApplication *native;

public:
    void __construct();

    Php::Value exec();

    static Php::Class<Application> _DEFINITION()
    {
        Php::Class<Application> application("Qt\\Widgets\\Application");
        application.method<&Application::__construct>("__construct");
        application.method<&Application::exec>("exec");

        return application;
    }
};