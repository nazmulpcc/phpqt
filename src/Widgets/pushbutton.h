#include<phpcpp.h>
#include<QtWidgets/QPushButton>

class PushButton : public Php::Base
{
private:
    QPushButton *native;

public:
    void __construct(Php::Parameters &params);
    void onPressed(Php::Parameters &params);

    static Php::Class<PushButton> _DEFINITION()
    {
        Php::Class<PushButton> pushbutton("Qt\\Widgets\\PushButton");
        pushbutton.method<&PushButton::__construct>("__construct", {
            Php::ByVal("name", Php::Type::String, true),
            Php::ByRef("parent", Php::Type::Object, true)
        });

        pushbutton.method<&PushButton::onPressed>("onPressed", {
            Php::ByVal("callback", Php::Type::Callable, true)
        });

        return pushbutton;
    }
};