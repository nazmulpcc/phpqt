#include <phpcpp.h>
#include "label.h"
#include "../macros.h"

void Label::__construct(Php::Parameters &params)
{
    this->native = new QLabel;
    this->label = dynamic_cast<QLabel *>(this->native);
    if (!params.empty())
    {
        this->setText(params);
    }
}

void Label::setText(Php::Parameters &params)
{
    QString label = QString::fromStdString(params[0].stringValue());
    this->label->setText(label);
}

FORWARD_CALL(Label, Widget, show)
