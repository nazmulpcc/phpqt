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

void Label::setAlignment(Php::Parameters &params)
{
    auto alignment = static_cast<Qt::Alignment>((int)params[0].numericValue());
    return this->native->setAlignment(alignment);
}

void Label::setText(Php::Parameters &params)
{
    QString label = QString::fromStdString(params[0].stringValue());
    this->native->setText(label);
}
