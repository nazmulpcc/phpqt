#include "Pixmap.h"

const QPixmap *Pixmap::getNative() {
    return this->native;
}

void Pixmap::setNative(const QPixmap *n)
{
    this->native = n;
}

void Pixmap::__construct(Php::Parameters &params)
{
    const std::string fileName = params[0].stringValue();
    const char *format = nullptr;
    Qt::ImageConversionFlags flags = Qt::AutoColor;
    if (params.size() > 1) {
        format = params[1].stringValue().c_str();
    }
    this->setNative(new QPixmap(QString::fromStdString(fileName), format, flags));
}
