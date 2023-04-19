#ifndef QT_H
#define QT_H

#include<phpcpp.h>
#include<QtCore/qnamespace.h>

class QtConstants : public Php::Base
{
public:
    static Php::Class<QtConstants> _DEFINITION()
    {
        Php::Class<QtConstants>definition("Qt");

        // Qt::AspectRatioMode
        definition.constant("IgnoreAspectRatio", Qt::IgnoreAspectRatio);
        definition.constant("KeepAspectRatio", Qt::KeepAspectRatio);
        definition.constant("KeepAspectRatioByExpanding", Qt::KeepAspectRatioByExpanding);

        // Qt::TimerType
        definition.constant("PreciseTimer", Qt::PreciseTimer);
        definition.constant("CoarseTimer", Qt::CoarseTimer);
        definition.constant("VeryCoarseTimer", Qt::VeryCoarseTimer);

        // Qt::TransformationMode
        definition.constant("FastTransformation", Qt::FastTransformation);
        definition.constant("SmoothTransformation", Qt::SmoothTransformation);

        // Qt::AlignmentFlag
        definition.constant("AlignLeft", Qt::AlignLeft);
        definition.constant("AlignLeading", Qt::AlignLeading);
        definition.constant("AlignRight", Qt::AlignRight);
        definition.constant("AlignTrailing", Qt::AlignTrailing);
        definition.constant("AlignHCenter", Qt::AlignHCenter);
        definition.constant("AlignJustify", Qt::AlignJustify);
        definition.constant("AlignAbsolute", Qt::AlignAbsolute);
        definition.constant("AlignHorizontal_Mask", Qt::AlignHorizontal_Mask);
        definition.constant("AlignTop", Qt::AlignTop);
        definition.constant("AlignBottom", Qt::AlignBottom);
        definition.constant("AlignVCenter", Qt::AlignVCenter);
        definition.constant("AlignBaseline", Qt::AlignBaseline);
        definition.constant("AlignVertical_Mask", Qt::AlignVertical_Mask);
        definition.constant("AlignCenter", Qt::AlignCenter);

        return definition;
    }
};


#endif
