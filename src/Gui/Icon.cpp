#include "Icon.h"
#include "Pixmap.h"
#include <QtCore/QString>

QIcon *Icon::getNative()
{
    return this->native;
}

void Icon::setNative(QIcon *n)
{
    this->native = n;
}

void Icon::__construct(Php::Parameters &params)
{
    std::string fileName;
    auto pixmap = params[0].implementation<Pixmap>();
    if (pixmap != nullptr) {
        const QPixmap *nativePixmap = const_cast<QPixmap *>(pixmap->getNative());
        this->setNative(new QIcon(*nativePixmap));
    } else {
        this->setNative(new QIcon(QString::fromStdString(params[0].stringValue())));
    }
}
