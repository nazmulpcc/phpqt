#include<phpcpp.h>
#include <QtWidgets/QLabel>

class Label : public Php::Base
{
private:
    QLabel* native;

public:
    void __construct(Php::Parameters &params);
    void setText(Php::Parameters &params);
    void show();

    QLabel* getNative();
    void setNative(QLabel *n);

    static Php::Class<Label> _DEFINITION()
    {
        Php::Class<Label> label("Qt\\Widgets\\Label");
        label.method<&Label::__construct>("__construct", {
            Php::ByVal("text", Php::Type::String, false)
        });
        label.method<&Label::setText>("setText", {Php::ByVal("text", Php::Type::String, false)});
        label.method<&Label::show>("show");

        return label;
    }
};