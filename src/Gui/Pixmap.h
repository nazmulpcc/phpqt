#ifndef PIXMAP_H
#define PIXMAP_H

#include <phpcpp.h>
#include <QtGui/QPixmap>

class Pixmap : public Php::Base
{
private:
    QPixmap *native;

public:
    inline static const char *CLASSPATH = "Qt\\Gui\\Pixmap";

    QPixmap *getNative();
    void setNative(QPixmap *n);

    void __construct(Php::Parameters &params);

    Php::Value cacheKey();
    Php::Value convertFromImage(Php::Parameters &params);
    Php::Value copy(Php::Parameters &params);
    Php::Value createHeuristicMask(Php::Parameters &params);
    Php::Value createMaskFromColor(Php::Parameters &params);
    Php::Value depth();
    void detach();
    Php::Value devicePixelRatio();
    void fill(Php::Parameters &params);
    Php::Value hasAlpha();
    Php::Value hasAlphaChannel();
    Php::Value height();
    Php::Value isNull();
    Php::Value load(Php::Parameters &params);
    Php::Value loadFromData(Php::Parameters &params);
    Php::Value mask();
    Php::Value rect();
    Php::Value save(Php::Parameters &params);
    Php::Value scaled(Php::Parameters &params);
    Php::Value scaledToHeight(Php::Parameters &params);
    Php::Value scaledToWidth(Php::Parameters &params);
    void setDevicePixelRatio(Php::Parameters &params);
    void setMask(Php::Parameters &params);
    Php::Value size();
    void swap(Php::Parameters &params);
    Php::Value toImage();
    Php::Value transformed(Php::Parameters &params);
    Php::Value width();

    static Php::Class<Pixmap> _DEFINITION() {
        Php::Class<Pixmap> definition(Pixmap::CLASSPATH);

        definition.method<&Pixmap::__construct>("__construct", {
            Php::ByVal("fileName", Php::Type::String, true),
            Php::ByVal("format", Php::Type::String, false),
            Php::ByVal("flags", Php::Type::Numeric, false)
        });
        definition.method<&Pixmap::cacheKey>("cacheKey");
        definition.method<&Pixmap::convertFromImage>("convertFromImage", {
            Php::ByRef("image", Php::Type::Object, true),
            Php::ByVal("flags", Php::Type::Numeric, false)
        });
        definition.method<&Pixmap::copy>("copy", {
            Php::ByVal("x", Php::Type::Numeric, true),
            Php::ByVal("y", Php::Type::Numeric, true),
            Php::ByVal("w", Php::Type::Numeric, true),
            Php::ByVal("h", Php::Type::Numeric, true)
        });
        definition.method<&Pixmap::createHeuristicMask>("createHeuristicMask", {
            Php::ByVal("clipTight", Php::Type::Bool, true)
        });
        definition.method<&Pixmap::createMaskFromColor>("createMaskFromColor", {
            Php::ByVal("maskColor", Php::Type::Object, true),
            Php::ByVal("mode", Php::Type::Numeric, true)
        });
        // definition.method<&Pixmap::cacheKey>("cacheKey");
        definition.method<&Pixmap::depth>("depth");
        definition.method<&Pixmap::detach>("detach");
        definition.method<&Pixmap::devicePixelRatio>("devicePixelRatio");
        definition.method<&Pixmap::fill>("fill", {
            Php::ByRef("color", Php::Type::Object, false),
        });
        definition.method<&Pixmap::hasAlpha>("hasAlpha");
        definition.method<&Pixmap::hasAlphaChannel>("hasAlphaChannel");
        definition.method<&Pixmap::height>("height");
        definition.method<&Pixmap::isNull>("isNull");
        definition.method<&Pixmap::load>("load", {
            Php::ByVal("fileName", Php::Type::String, true),
            Php::ByVal("format", Php::Type::String, false),
            Php::ByVal("flags", Php::Type::Numeric, false)
        });
        definition.method<&Pixmap::loadFromData>("loadFromData", {
            Php::ByVal("data", Php::Type::String, true),
            Php::ByVal("length", Php::Type::Numeric, true),
            Php::ByVal("format", Php::Type::String, false),
            Php::ByVal("flags", Php::Type::Numeric, false)
        });
        definition.method<&Pixmap::mask>("mask");
        definition.method<&Pixmap::rect>("rect");
        definition.method<&Pixmap::save>("save", {
            Php::ByVal("fileName", Php::Type::String, true),
            Php::ByVal("format", Php::Type::String, false),
            Php::ByVal("quality", Php::Type::Numeric, false)
        });
        definition.method<&Pixmap::scaled>("scaled", {
            Php::ByVal("width", Php::Type::Numeric, true),
            Php::ByVal("height", Php::Type::Numeric, true),
            Php::ByVal("aspectRatioMode", Php::Type::Numeric, false),
            Php::ByVal("transformMode", Php::Type::Numeric, false)
        });
        definition.method<&Pixmap::scaledToHeight>("scaledToHeight", {
            Php::ByVal("height", Php::Type::Numeric, true),
            Php::ByVal("transformMode", Php::Type::Numeric, false)
        });
        definition.method<&Pixmap::scaledToWidth>("scaledToWidth", {
            Php::ByVal("width", Php::Type::Numeric, true),
            Php::ByVal("transformMode", Php::Type::Numeric, false)
        });
        definition.method<&Pixmap::setDevicePixelRatio>("setDevicePixelRatio", {
            Php::ByVal("scaleFactor", Php::Type::Float, true)
        });
        definition.method<&Pixmap::setMask>("setMask", {
            Php::ByRef("mask", Php::Type::Object, true)
        });
        definition.method<&Pixmap::size>("size");
        definition.method<&Pixmap::swap>("swap", {
            Php::ByRef("other", Php::Type::Object, true)
        });
        definition.method<&Pixmap::toImage>("toImage");
        definition.method<&Pixmap::transformed>("transformed", {
            Php::ByRef("transform", Php::Type::Object, true),
            Php::ByVal("mode", Php::Type::Object, true)
        });
        definition.method<&Pixmap::width>("width");

        return definition;
    }
};

#endif
