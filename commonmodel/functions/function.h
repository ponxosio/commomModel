#ifndef FUNCTION_H
#define FUNCTION_H

#include <cstdarg>
#include <memory>
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
        stir,
        centrifugate,
        shake,
        electrophoresis,
        measure_temperature,
        measure_luminiscence,
        measure_fluorescence,
        measure_volume,
        MAX_OPTYPE = measure_volume + 1 //ALWAYS EQUALS TO THE SECOND-TO-LAST TYPE PLUS ONE
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
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw(std::invalid_argument) = 0;
    virtual units::Volume getMinVolume() = 0;
    virtual bool inWorkingRange(int nargs, va_list args) throw(std::invalid_argument) = 0;

    inline void setFactory(std::shared_ptr<PluginAbstractFactory> factory) {
        this->factory = factory;
    }

protected:
    std::shared_ptr<PluginAbstractFactory> factory;
};

#endif // FUNCTION_H
