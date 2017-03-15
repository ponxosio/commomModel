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
    ComponentInterface(const ComponentInterface & obj) : availableFunctios(obj.availableFunctios){}
    virtual ~ComponentInterface(){}

    virtual bool canDoOperations(unsigned long mask) = 0;
    virtual double doOperation(Function::OperationType op, int nargs, ...) throw (std::invalid_argument) = 0;
    virtual double getMinVolume(Function::OperationType op) throw (std::invalid_argument) = 0;

    inline const FunctionSet & getAvailableFunctions() const {
        return availableFunctios;
    }
protected:
    FunctionSet availableFunctios;
};
#endif // COMPONENTINTERFACE_H
