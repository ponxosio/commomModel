#ifndef FUNCTIONSET_H
#define FUNCTIONSET_H

#include <bitset>
#include <unordered_map>
#include <memory>
#include <cstdarg>
#include <stdexcept>

#include <utils/units.h>
#include <utils/multiunitswrapper.h>

#include "commonmodel/functions/function.h"
#include "commonmodel/plugininterface/pluginabstractfactory.h"

#include "commonmodel/commommodel_global.h"

class FUNCTIONSET_EXPORT FunctionSet
{
public:
    FunctionSet();
    FunctionSet(const FunctionSet & set);
    virtual ~FunctionSet();

    bool canDoOperations(unsigned long mask);
    std::shared_ptr<MultiUnitsWrapper> doOperation(Function::OperationType op, int nargs, va_list args) throw(std::invalid_argument);
    bool inWorkingRange(Function::OperationType op, int nargs, va_list args) throw(std::invalid_argument);

    units::Volume getMinVolume(Function::OperationType op) throw(std::invalid_argument);
    void addOperation(std::shared_ptr<Function> function);

    void setFactory(std::shared_ptr<PluginAbstractFactory> factory);
    void setFactory(Function::OperationType op, std::shared_ptr<PluginAbstractFactory> factory) throw(std::invalid_argument);

protected:
    std::bitset<Function::MAX_OPERATION_TYPE> aceptedFunctions;
    std::unordered_map<int,std::shared_ptr<Function>> functionsMap;
};

#endif // FUNCTIONSET_H
