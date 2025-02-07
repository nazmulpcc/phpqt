#include <phpcpp.h>
#include "src/QtConstants.h"
#include "src/Core/Event.h"
#include "src/Core/TimerEvent.h"
#include "src/Core/Object.h"
#include "src/Core/Size.h"
#include "src/Core/Thread.h"
#include "src/Core/Action.h"
#include "src/Widgets/application.h"
#include "src/Widgets/BoxLayout.h"
#include "src/Widgets/VBoxLayout.h"
#include "src/Widgets/FormLayout.h"
#include "src/Widgets/widget.h"
#include "src/Widgets/Layout.h"
#include "src/Widgets/label.h"
#include "src/Widgets/LineEdit.h"
#include "src/Widgets/mainwindow.h"
#include "src/Widgets/ProgressBar.h"
#include "src/Widgets/textedit.h"
#include "src/Widgets/pushbutton.h"
#include "src/Gui/Pixmap.h"
#include "src/Gui/Icon.h"

class PhpQApplication
{
};

extern "C"
{
    PHPCPP_EXPORT void *get_module()
    {
        static Php::Extension extension("phpqt", "1.0");

        auto qt = QtConstants::_DEFINITION();

        auto event = Event::_DEFINITION();
        auto object = Object::_DEFINITION();
        auto widget = Widget::_DEFINITION();
        auto layout = Layout::_DEFINITION();

        auto size = Size::_DEFINITION();
        auto thread = Thread::_DEFINITION();
        auto timerevent = TimerEvent::_DEFINITION();
        auto action = Action::_DEFINITION();
        auto application = Application::_DEFINITION();
        auto boxLayout = BoxLayout::_DEFINITION();
        auto vboxLayout = VBoxLayout::_DEFINITION();
        auto formLayout = FormLayout::_DEFINITION();
        auto label = Label::_DEFINITION();
        auto lineEdit = LineEdit::_DEFINITION();
        auto mainwindow = MainWindow::_DEFINITION();
        auto progressbar = ProgressBar::_DEFINITION();
        auto pushbutton = PushButton::_DEFINITION();
        auto textedit = TextEdit::_DEFINITION();

        auto pixmap = Pixmap::_DEFINITION();
        auto icon = Icon::_DEFINITION();

        widget.extends(object);
        layout.extends(object);
        timerevent.extends(event);

        action.extends(object);
        thread.extends(object);
        formLayout.extends(layout);
        boxLayout.extends(layout);
        vboxLayout.extends(boxLayout);
        label.extends(widget);
        mainwindow.extends(widget);
        pushbutton.extends(widget);
        progressbar.extends(widget);
        textedit.extends(widget);
        lineEdit.extends(widget);

        extension
            .add(qt)
            .add(object)
            .add(event)
            .add(timerevent)
            .add(size)
            .add(thread)
            .add(widget)
            .add(action)
            .add(layout)
            .add(application)
            .add(formLayout)
            .add(boxLayout)
            .add(vboxLayout)
            .add(label)
            .add(lineEdit)
            .add(mainwindow)
            .add(pushbutton)
            .add(progressbar)
            .add(textedit)
            .add(pixmap)
            .add(icon);

        return extension;
    }
}