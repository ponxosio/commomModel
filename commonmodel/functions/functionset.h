#ifndef FUNCTIONSET_H
#define FUNCTIONSET_H

#define ROUTE_FLAG 1
#define PUMP_FLAG 2
#define HEAT_FLAG 4
#define LIGHT_FLAG 8
#define MEASUREOD_FLAG 16
#define STIR_FLAG 32

#include <bitset>
#include <unordered_map>
#include <memory>
#include <cstdarg>
#include <stdexcept>

#include "commonmodel/functions/function.h"
#include "commonmodel/plugininterface/pluginabstractfactory.h"

class FunctionSet
{
public:
    FunctionSet();
    FunctionSet(const FunctionSet & set);
    virtual ~FunctionSet();

    bool canDoOperations(unsigned long mask);
    double doOperation(Function::OperationType op, int nargs, va_list args) throw(std::invalid_argument);
    double getMinVolume(Function::OperationType op) throw(std::invalid_argument);
    void addOperation(std::shared_ptr<Function> function);

    void setFactory(std::shared_ptr<PluginAbstractFactory> factory);
    void setFactory(Function::OperationType op, std::shared_ptr<PluginAbstractFactory> factory) throw(std::invalid_argument);

protected:
    std::bitset<6> aceptedFunctions;
    std::unordered_map<int,std::shared_ptr<Function>> functionsMap;
};

#endif // FUNCTIONSET_H
