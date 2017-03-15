#ifndef FUNCTION_H
#define FUNCTION_H

#include <cstdarg>
#include <stdexcept>

#include "commonmodel/plugininterface/pluginabstractfactory.h"

class Function
{
public:
    typedef enum _OperationType {
        route = 1,
        pump = 2,
        heat = 4,
        apply_light = 8,
        measure_od = 16,
        stir = 32
    } OperationType;

    Function(std::shared_ptr<PluginAbstractFactory> factory) {
        this->factory = factory;
    }
    virtual ~Function(){}

    virtual OperationType getAceptedOp() = 0;
    virtual double doOperation(int nargs, va_list args) throw(std::invalid_argument) = 0;
    virtual double getMinVolume() = 0;

    inline void setFactory(std::shared_ptr<PluginAbstractFactory> factory) {
        this->factory = factory;
    }

protected:
    std::shared_ptr<PluginAbstractFactory> factory;
};

#endif // FUNCTION_H
