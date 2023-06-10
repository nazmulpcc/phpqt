#include "ProgressBar.h"
#include <QtWidgets/QProgressBar>

void ProgressBar::__construct(Php::Parameters &params)
{
    this->native = new QProgressBar;
    if (!params.empty()) {
        auto parent = params[1].implementation<Widget>()->getNative();
        this->native->setParent(parent);
    }
    setNative(this->native);
}

Php::Value ProgressBar::value()
{
    return Php::Value((int64_t) this->native->value());
}

void ProgressBar::setValue(Php::Parameters &params)
{
    this->native->setValue(params[0].numericValue());
}
