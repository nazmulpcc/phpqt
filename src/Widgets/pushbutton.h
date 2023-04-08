#include "widget.h"
#include<phpcpp.h>
#include<QtWidgets/QPushButton>

class PushButton : public Widget
{
private:
    QPushButton *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\PushButton";

    void __construct(Php::Parameters &params);
    void onClicked(Php::Parameters &params);
    void onPressed(Php::Parameters &params);
    void onReleased(Php::Parameters &params);

    static Php::Class<PushButton> _DEFINITION()
    {
        Php::Class<PushButton> pushbutton(PushButton::CLASSPATH.c_str());
        pushbutton.method<&PushButton::__construct>("__construct", {
            Php::ByVal("name", Php::Type::String, true),
            Php::ByRef("parent", Php::Type::Object, false)
        });

        pushbutton.method<&PushButton::onPressed>("onPressed", {Php::ByVal("callback", Php::Type::Callable, true)});
        pushbutton.method<&PushButton::onClicked>("onClicked", {Php::ByVal("callback", Php::Type::Callable, true)});
        pushbutton.method<&PushButton::onReleased>("onReleased", {Php::ByVal("callback", Php::Type::Callable, true)});

        return pushbutton;
    }
};