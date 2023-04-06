#include "widget.h"
#include "FormLayout.h"

void FormLayout::__construct(Php::Parameters &params)
{
    QWidget *parent = nullptr;
    if (params.size() > 0) {
        params[0].implementation<QWidget>();
    }
    
    this->native = new QFormLayout(parent);
    setNative(this->native);
}

void FormLayout::addRow(Php::Parameters &params)
{
    QString label;
    Widget *labelWidget = nullptr;
    Widget *field = nullptr;
    QLayout *layout = nullptr;

    if (params.size() == 1) {
        field = params[0].implementation<Widget>();
        if (field == nullptr) {
            layout = params[0].implementation<QLayout>();
            this->native->addRow(layout);
        }else{
            this->native->addRow(field->getNative());
        }
        return;
    }
    labelWidget = params[0].implementation<Widget>();
    if (labelWidget == nullptr) {
        label = QString::fromStdString(params[0].stringValue());
    }
    field = params[1].implementation<Widget>();
    if (field == nullptr) {
        layout = params[1].implementation<QLayout>();
    }
    if (labelWidget == nullptr){
        if (field == nullptr) {
            this->native->addRow(label, layout);
        }else{
            this->native->addRow(label, field->getNative());
        }
    }else{
        if (field == nullptr){
            this->native->addRow(labelWidget->getNative(), layout);
        }else{
            this->native->addRow(labelWidget->getNative(), field->getNative());
        }
    }
}
