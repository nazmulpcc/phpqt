#include <phpcpp.h>
#include "label.h"

void Label::__construct(Php::Parameters &params)
{
    this->native = new QLabel;
    if (!params.empty())
    {
        this->setText(params);
    }
}

void Label::show()
{
    this->native->show();
}

void Label::setText(Php::Parameters &params)
{
    QString label = QString::fromStdString((std::string)params[0]);
    this->native->setText(label);
}

QLabel* Label::getNative()
{
    return this->native;
}