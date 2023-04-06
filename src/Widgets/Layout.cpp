#include "Layout.h"
#include <QtWidgets/QLayout>

void Layout::setNative(QLayout *n) {
    this->native = n;
}

QLayout *Layout::getNative() {
    return this->native;
}