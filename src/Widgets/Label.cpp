#include <phpcpp.h>
#include "label.h"
#include "../Gui/Pixmap.h"
#include <QtGui/QPixmap>

void Label::__construct(Php::Parameters &params)
{
    this->native = new QLabel;
    setNative(this->native);
    if (!params.empty())
    {
        this->setText(params);
    }
}

Php::Value Label::pixmap()
{
    auto pixmap = new Pixmap;
    auto nativePixmap = this->native->pixmap(Qt::ReturnByValue);
    pixmap->setNative(&nativePixmap);
    return Php::Object(Pixmap::CLASSPATH, pixmap);
}

void Label::setAlignment(Php::Parameters &params)
{
    auto alignment = static_cast<Qt::Alignment>((int)params[0].numericValue());
    return this->native->setAlignment(alignment);
}

void Label::setPixmap(Php::Parameters &params)
{
    auto *pixmap = params[0].implementation<Pixmap>();
    this->native->setPixmap(*pixmap->getNative());
}

void Label::setText(Php::Parameters &params)
{
    QString label = QString::fromStdString(params[0].stringValue());
    this->native->setText(label);
}
