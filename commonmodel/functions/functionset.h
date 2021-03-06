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
    typedef std::unordered_map<Function::OperationType,unsigned long, Function::OperationTypeHash> FlagMap;

    static const FlagMap FUNCTIONS_FLAG_MAP;

    FunctionSet();
    FunctionSet(const FunctionSet & set);
    virtual ~FunctionSet();

    bool canDoOperations(unsigned long mask) const;
    std::shared_ptr<MultiUnitsWrapper> doOperation(Function::OperationType op, int nargs, va_list args) throw(std::invalid_argument);

    bool inWorkingRange(Function::OperationType op, int nargs, va_list args) const throw(std::invalid_argument);
    const std::shared_ptr<const ComparableRangeInterface> getComparableWorkingRange(Function::OperationType op) const throw(std::invalid_argument);

    units::Volume getMinVolume(Function::OperationType op) const throw(std::invalid_argument);
    void addOperation(std::shared_ptr<Function> function);

    void setFactory(std::shared_ptr<PluginAbstractFactory> factory);
    void setFactory(Function::OperationType op, std::shared_ptr<PluginAbstractFactory> factory) throw(std::invalid_argument);

    void stopAllOperations();

    inline unsigned long getAvailableOperations() const {
        return aceptedFunctions.to_ulong();
    }
    inline const std::bitset<Function::MAX_OPTYPE> & getAceptedFunctions() const {
        return aceptedFunctions;
    }

protected:
    static FlagMap createFlagMap();

    std::bitset<Function::MAX_OPTYPE> aceptedFunctions;
    std::unordered_map<int,std::shared_ptr<Function>> functionsMap;
};

#endif // FUNCTIONSET_H
