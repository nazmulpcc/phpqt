#include <phpcpp.h>
#include "label.h"

void Label::__construct(Php::Parameters &params)
{
    this->native = new QLabel;
    setNative(this->native);
    if (!params.empty())
    {
        this->setText(params);
    }
}

void Label::setText(Php::Parameters &params)
{
    QString label = QString::fromStdString(params[0].stringValue());
    this->native->setText(label);
}
