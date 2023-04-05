#ifndef MACROS_H
#define MACROS_H

#define FORWARD_CALL(CHILD_CLASS, PARENT_CLASS, METHOD) \
    void CHILD_CLASS::METHOD()                          \
    {                                                   \
        PARENT_CLASS::METHOD();                         \
    }

#define OVERRIDE_METHOD(METHOD) \
    void METHOD() override;

#endif