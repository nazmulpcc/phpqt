#include <phpcpp.h>
#include <QtWidgets/QApplication>

class Application : public Php::Base
{
private:
    QApplication *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\Application";

    void __construct();
    Php::Value exec();
    void quit();

    static Php::Class<Application> _DEFINITION()
    {
        Php::Class<Application> application(Application::CLASSPATH.c_str());
        application.method<&Application::__construct>("__construct");
        application.method<&Application::exec>("exec");
        application.method<&Application::quit>("quit");

        return application;
    }
};