#ifndef PIXMAP_H
#define PIXMAP_H

#include <phpcpp.h>
#include <QtGui/QPixmap>

class Pixmap : public Php::Base
{
private:
    const QPixmap *native;

public:
    inline static const char *CLASSPATH = "Qt\\Gui\\Pixmap";

    const QPixmap *getNative();
    void setNative(const QPixmap *n);

    void __construct(Php::Parameters &params);

    static Php::Class<Pixmap> _DEFINITION() {
        Php::Class<Pixmap> definition(Pixmap::CLASSPATH);

        definition.method<&Pixmap::__construct>("__construct", {
            Php::ByVal("fileName", Php::Type::String, true),
            Php::ByVal("format", Php::Type::String, false),
            Php::ByVal("flags", Php::Type::Numeric, false)
        });

        return definition;
    }
};

#endif
