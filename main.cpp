#include <phpcpp.h>
#include "src/Widgets/widget.h"
#include "src/Widgets/label.h"
#include "src/Widgets/application.h"
#include "src/Widgets/mainwindow.h"
#include "src/Widgets/textedit.h"
#include "src/Widgets/pushbutton.h"

class PhpQApplication
{};

extern "C" {
    PHPCPP_EXPORT void *get_module()
    {
        static Php::Extension extension("phpqt", "1.0");

        auto widget = Widget::_DEFINITION();

        auto application = Application::_DEFINITION();
        auto label = Label::_DEFINITION();
        auto mainwindow = MainWindow::_DEFINITION();
        auto pushbutton = PushButton::_DEFINITION();
        auto textedit = TextEdit::_DEFINITION();

        label.extends(widget);
        mainwindow.extends(widget);
        pushbutton.extends(widget);
        textedit.extends(widget);

        extension
            .add(widget)
            .add(application)
            .add(label)
            .add(mainwindow)
            .add(pushbutton)
            .add(textedit);

        return extension;
    }
}