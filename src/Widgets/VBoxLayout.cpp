#include "VBoxLayout.h"
#include "widget.h"
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

void VBoxLayout::__construct(Php::Parameters &params)
{
    QWidget *parent = nullptr;
    if (params.size() > 0) {
        parent = params[0].implementation<Widget>()->getNative();
    }
    this->native = new QVBoxLayout(parent);
    BoxLayout::setNative(this->native);
}
