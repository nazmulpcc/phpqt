#include "Pixmap.h"
#include <QtGui/QPixmap>

QPixmap *Pixmap::getNative() {
    return this->native;
}

void Pixmap::setNative(QPixmap *n)
{
    this->native = n;
}

void Pixmap::__construct(Php::Parameters &params)
{
    if (params.size() == 1) {
        auto pixmap = params[0].implementation<Pixmap>();
        if (pixmap != nullptr) {
            this->setNative(pixmap->getNative());
            return;
        }
    }
    
    this->setNative(new QPixmap);
    this->load(params); // delegate the initialization to the load method, it has the same signatures
}

Php::Value Pixmap::cacheKey()
{
    return Php::Value(this->native->cacheKey());
}

Php::Value Pixmap::convertFromImage(Php::Parameters &params)
{
    // TODO: Implement QImage
    return Php::Value(0);
}

Php::Value Pixmap::copy(Php::Parameters &params)
{
    const auto pixmap = new Pixmap;
    auto nativePixmap = this->native->copy(
        params[0].numericValue(),
        params[1].numericValue(),
        params[2].numericValue(),
        params[3].numericValue()
    );
    pixmap->setNative(&nativePixmap);
    return Php::Object(Pixmap::CLASSPATH, pixmap);
}

Php::Value Pixmap::createHeuristicMask(Php::Parameters &params)
{
    // TODO: Implement QBitmap
    return Php::Value(0);
}

Php::Value Pixmap::createMaskFromColor(Php::Parameters &params)
{
    // TODO: Implement QBitmap & QColor
    return Php::Value();
}

Php::Value Pixmap::depth()
{
    return Php::Value(this->native->depth());
}

void Pixmap::detach()
{
    this->native->detach();
}

Php::Value Pixmap::devicePixelRatio()
{
    return Php::Value(this->native->devicePixelRatio());
}

void Pixmap::fill(Php::Parameters &params)
{
    // TODO: Implement QColor
}

Php::Value Pixmap::hasAlpha()
{
    return Php::Value(this->native->hasAlpha());
}

Php::Value Pixmap::hasAlphaChannel()
{
    return Php::Value(this->native->hasAlphaChannel());
}

Php::Value Pixmap::height()
{
    return Php::Value(this->native->height());
}

Php::Value Pixmap::isNull()
{
    return Php::Value(this->native->isNull());
}

Php::Value Pixmap::load(Php::Parameters &params)
{
    const std::string fileName = params[0].stringValue();
    const char *format = nullptr;
    Qt::ImageConversionFlags flags = Qt::AutoColor;
    if (params.size() > 1)
    {
        format = params[1].stringValue().c_str();
    }
    
    return Php::Value(this->native->load(QString::fromStdString(fileName), format, flags));
}

Php::Value Pixmap::loadFromData(Php::Parameters &params)
{
    // TODO: implement loading from string data
    return Php::Value(0);
}

Php::Value Pixmap::mask()
{
    // TODO: implement QBitmap
    return Php::Value(0);
}

Php::Value Pixmap::rect()
{
    // TODO: implement QRect
    return Php::Value(0);
}

Php::Value Pixmap::save(Php::Parameters &params)
{
    auto filePath = QString::fromStdString(params[0].stringValue());
    const char *format = nullptr;
    int quality = -1;
    if (params.size() > 1) {
        format = params[1].stringValue().c_str();
    }
    if (params.size() > 2) {
        quality = params[2].numericValue();
    }

    return Php::Value(this->native->save(filePath, format, quality));
}

Php::Value Pixmap::scaled(Php::Parameters &params)
{
    int width = params[0].numericValue();
    int height = params[1].numericValue();
    auto aspectRatioMode = Qt::IgnoreAspectRatio;
    auto transformMode = Qt::FastTransformation;
    if (params.size() > 2) {
        aspectRatioMode = static_cast<Qt::AspectRatioMode>(params[2].numericValue());
    }
    if (params.size() > 3) {
        transformMode = static_cast<Qt::TransformationMode>(params[3].numericValue());
    }
    auto pixmap = new Pixmap;
    auto nativePixmap = this->native->scaled(width, height, aspectRatioMode, transformMode);
    pixmap->setNative(&nativePixmap);

    return Php::Object(Pixmap::CLASSPATH, pixmap);
}

Php::Value Pixmap::scaledToHeight(Php::Parameters &params)
{
    int height = params[0].numericValue();
    auto transformMode = Qt::FastTransformation;
    if (params.size() > 1) {
        transformMode = static_cast<Qt::TransformationMode>(params[1].numericValue());
    }
    auto pixmap = new Pixmap;
    auto nativePixmap = this->native->scaledToHeight(height, transformMode);
    pixmap->setNative(&nativePixmap);
    
    return Php::Object(Pixmap::CLASSPATH, pixmap);
}

Php::Value Pixmap::scaledToWidth(Php::Parameters &params)
{
    int width = params[0].numericValue();
    auto transformMode = Qt::FastTransformation;
    if (params.size() > 1) {
        transformMode = static_cast<Qt::TransformationMode>(params[1].numericValue());
    }
    auto pixmap = new Pixmap;
    auto nativePixmap = this->native->scaledToWidth(width, transformMode);
    pixmap->setNative(&nativePixmap);

    return Php::Object(Pixmap::CLASSPATH, pixmap);
}

void Pixmap::setDevicePixelRatio(Php::Parameters &params)
{
    this->native->setDevicePixelRatio(params[0].floatValue());
}

void Pixmap::setMask(Php::Parameters &params)
{
    // TODO: implement QBitmap
}

Php::Value Pixmap::size()
{
    // TODO: implement QSize
    return Php::Value(0);
}

Php::Value Pixmap::toImage()
{
    // TODO: implement QImage
    return Php::Value(0);
}

Php::Value Pixmap::transformed(Php::Parameters &params)
{
    // TODO: implement QTransform
    return Php::Value(0);
}

Php::Value Pixmap::width()
{
    return Php::Value(this->native->width());
}

void Pixmap::swap(Php::Parameters &params)
{
    // TODO: implement swap method
}