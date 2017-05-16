#ifndef FUNCTION_H
#define FUNCTION_H

#include <cstdarg>
#include <stdexcept>

#include <utils/units.h>
#include <utils/multiunitswrapper.h>

#include "commonmodel/plugininterface/pluginabstractfactory.h"

class Function
{
public:
    typedef enum _OperationType {
        route,
        pump,
        heat,
        apply_light,
        measure_od,
        measure_temperature,
        measure_luminousIntensity,
        measure_fluorescence,
        measure_volume,
        stir,
        MAX_OPTYPE = stir + 1
    } OperationType;

    typedef struct _OperationTypeHash {
        size_t operator()(OperationType x) const throw () {
            return ((size_t)x);
        }
    }OperationTypeHash;

    Function(std::shared_ptr<PluginAbstractFactory> factory) {
        this->factory = factory;
    }
    virtual ~Function(){}

    virtual OperationType getAceptedOp() = 0;
    virtual MultiUnitsWrapper* doOperation(int nargs, va_list args) throw(std::invalid_argument) = 0;
    virtual units::Volume getMinVolume() = 0;

    inline void setFactory(std::shared_ptr<PluginAbstractFactory> factory) {
        this->factory = factory;
    }

protected:
    std::shared_ptr<PluginAbstractFactory> factory;
};

#endif // FUNCTION_H
