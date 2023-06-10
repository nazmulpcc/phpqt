#include "widget.h"
#include <phpcpp.h>
#include <QtWidgets/QProgressBar>

class ProgressBar : public Widget
{
private:
    QProgressBar *native;

public:
    inline static const std::string CLASSPATH = "Qt\\Widgets\\ProgressBar";

    void __construct(Php::Parameters &params);
    Php::Value value();
    void setValue(Php::Parameters &params);

    static Php::Class<ProgressBar> _DEFINITION()
    {
        Php::Class<ProgressBar> progressbar(ProgressBar::CLASSPATH.c_str());
        
        progressbar.method<&ProgressBar::__construct>("__construct", {Php::ByRef("parent", Php::Type::Object, false)});
        progressbar.method<&ProgressBar::value>("value");
        progressbar.method<&ProgressBar::setValue>("setValue", {Php::ByVal("value", Php::Type::Numeric)});
        
        return progressbar;
    }
};