#include<phpcpp.h>
#include<QtWidgets/QApplication>

class Application : public Php::Base 
{
private:
    QApplication *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\Application";

    void __construct(Php::Parameters &params);
    Php::Value exec();

    static Php::Class<Application> _DEFINITION()
    {
        Php::Class<Application> application(Application::CLASSPATH.c_str());
        application.method<&Application::__construct>("__construct", {
            Php::ByVal("argc", Php::Type::Numeric, false),
            Php::ByVal("argv", Php::Type::Array, false)
        });
        application.method<&Application::exec>("exec");

        return application;
    }
};