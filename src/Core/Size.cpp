#include "Size.h"
#include <phpcpp.h>
#include <QtCore/QSize>

Size::Size(int width, int height)
{
    QSize *n = new QSize(width, height);
    setNative(n);
}

Size::Size(QSize *n)
{
    setNative(n);
}

QSize *Size::getNative() const
{
    return this->native;
}

void Size::setNative(QSize *n)
{
    this->native = n;
}

void Size::__construct(Php::Parameters &params)
{
    if (params.size() == 0) {
        this->setNative(new QSize);
        return;
    }
    int width = params[0].numericValue();
    int height = width;
    if (params.size() > 1) {
        height = params[1].numericValue();
    }
    this->setNative(new QSize(width, height));
}

int Size::__compare(const Size &other) const
{
    // TODO: for some reason size comparison doesn't work in PHP.
    auto n = other.getNative();
    if (this->native > n) return 1;
    if (this->native < n) return -1; 
    return 0;
}

Php::Value Size::boundedTo(Php::Parameters &params) const
{
    QSize other = this->native->boundedTo(*params[0].implementation<Size>()->getNative());
    return Php::Object(Size::CLASSPATH, new Size(&other));
}

Php::Value Size::expandedTo(Php::Parameters &params) const
{
    QSize other = this->native->expandedTo(*params[0].implementation<Size>()->getNative());
    return Php::Object(Size::CLASSPATH, new Size(&other));
}

Php::Value Size::grownBy(Php::Parameters &params) const
{
    // TODO: implement QMargins
    return Php::Value(this);
}

Php::Value Size::height() const
{
    return Php::Value(this->native->height());
}

Php::Value Size::isEmpty() const
{
    return Php::Value(this->native->isEmpty());
}

Php::Value Size::isNull() const
{
    return Php::Value(this->native->isNull());
}

Php::Value Size::isValid() const
{
    return Php::Value(this->native->isValid());
}

void Size::scale(Php::Parameters &params)
{
    Qt::AspectRatioMode mode;
    if (params.size() == 2){
        auto size = *params[0].implementation<Size>()->getNative();
        mode = static_cast<Qt::AspectRatioMode>(params[1].numericValue());
        this->native->scale(size, mode);
        return;
    }
    int width = params[0].numericValue();
    int height = params[1].numericValue();
    mode = static_cast<Qt::AspectRatioMode>(params[2].numericValue());
    this->native->scale(width, height, mode);
}

Php::Value Size::scaled(Php::Parameters &params)
{
    auto size = new Size(new QSize(this->width(), this->height()));
    size->scale(params);
    return Php::Object(Size::CLASSPATH, size);
}

Php::Value Size::width() const
{
    return Php::Value(this->native->width());
}

void Size::setHeight(Php::Parameters &params)
{
    this->native->setHeight(params[0].numericValue());
}

void Size::setWidth(Php::Parameters &params)
{
    this->native->setWidth(params[0].numericValue());
}

Php::Value Size::shrunkBy(Php::Parameters &params) const
{
    // TODO: implement QMargins
    return Php::Value(this);
}

void Size::transpose()
{
    this->native->transpose();
}

Php::Value Size::transposed() const
{
    auto size = new Size;
    size->setNative(new QSize(this->width(), this->height()));
    size->transpose();
    return Php::Object(Size::CLASSPATH, size);
}
