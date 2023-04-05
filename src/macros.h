#ifndef MACROS_H
#define MACROS_H

#define FORWARD_CALL(CHILD_CLASS, PARENT_CLASS, METHOD) \
    void CHILD_CLASS::METHOD()                          \
    {                                                   \
        PARENT_CLASS::METHOD();                         \
    }

#define FORWARD_CALL_WITH_PARAMS(CHILD_CLASS, PARENT_CLASS, METHOD) \
    void CHILD_CLASS::METHOD(Php::Parameters &params)   \
    {                                                   \
        PARENT_CLASS::METHOD(params);                   \
    }

#define OVERRIDE_METHOD(METHOD) \
    void METHOD() override;

#define OVERRIDE_METHOD_WITH_PARAMS(METHOD) \
    void METHOD(Php::Parameters &params) override;

#endif