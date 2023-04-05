#include <phpcpp.h>
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

        extension.add(std::move(Label::_DEFINITION()));

        extension.add(std::move(Application::_DEFINITION()));

        extension.add(std::move(MainWindow::_DEFINITION()));

        extension.add(std::move(TextEdit::_DEFINITION()));

        extension.add(std::move(PushButton::_DEFINITION()));

        return extension;
    }
}