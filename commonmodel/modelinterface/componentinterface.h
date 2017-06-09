#ifndef COMPONENTINTERFACE_H
#define COMPONENTINTERFACE_H

#include <cstdarg>
#include <memory>
#include <stdexcept>
#include <string>

#include <protocolGraph/ProtocolGraph.h>

#include "commonmodel/functions/function.h"
#include "commonmodel/functions/functionset.h"

class ComponentInterface {
public:
    ComponentInterface(){}
    ComponentInterface(const ComponentInterface & obj) : availableFunctions(obj.availableFunctions){}
    virtual ~ComponentInterface(){}

    virtual bool canDoOperations(unsigned long mask) const = 0;
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(Function::OperationType op, int nargs, ...) throw (std::invalid_argument) = 0;

    virtual bool inWorkingRange(Function::OperationType op, int nargs, ...) const throw (std::invalid_argument) = 0;
    virtual const std::shared_ptr<const ComparableRangeInterface> getComparableWorkingRange(Function::OperationType op) const = 0;

    virtual units::Volume getMinVolume(Function::OperationType op) const throw (std::invalid_argument) = 0;
    virtual units::Volume getActualVolume() const = 0;

    inline const FunctionSet & getAvailableFunctions() const {
        return availableFunctions;
    }
protected:
    FunctionSet availableFunctions;
};
#endif // COMPONENTINTERFACE_H
