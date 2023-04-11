#ifndef VBOXLAYOUT_H
#define VBOXLAYOUT_H

#include "BoxLayout.h"
#include <phpcpp.h>
#include <QtWidgets/QVBoxLayout>

class VBoxLayout : public BoxLayout {
private:
    QVBoxLayout *native;

public:
    inline static const char *CLASSPATH = "Qt\\Widgets\\VBoxLayout";

    void __construct(Php::Parameters &params);

    static Php::Class<VBoxLayout> _DEFINITION()
    {
        Php::Class<VBoxLayout>definition(VBoxLayout::CLASSPATH);

        definition.method<&VBoxLayout::__construct>("__construct", {Php::ByRef("parent", Php::Type::Object, false)});

        return definition;
    }
};

#endif // VBOXLAYOUT_H
