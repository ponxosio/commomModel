#include "functionset.h"

const FunctionSet::FlagMap FunctionSet::FUNCTIONS_FLAG_MAP = createFlagMap();

FunctionSet::FlagMap FunctionSet::createFlagMap() {
    FlagMap functionsMap;
    for(int i = 0; i < (Function::MAX_OPTYPE - 1); i++) {
        unsigned long flagValue = 1 << i;
        functionsMap.insert(std::make_pair((Function::OperationType) i, flagValue));
    }
    return functionsMap;
}

FunctionSet::FunctionSet()
{

}

FunctionSet::FunctionSet(const FunctionSet & set) :
    aceptedFunctions(set.aceptedFunctions)
{
    for (auto it: set.functionsMap) {
        functionsMap.insert(std::make_pair(it.first, it.second));
    }
}

FunctionSet::~FunctionSet() {

}

bool FunctionSet::canDoOperations(unsigned long mask) const {
    unsigned long posibleops = aceptedFunctions.to_ulong();
    return ((mask & posibleops) == mask);
}

std::shared_ptr<MultiUnitsWrapper> FunctionSet::doOperation(Function::OperationType op, int nargs, va_list args) throw (std::invalid_argument) {
    int castop = (int) op;

    auto it = functionsMap.find(castop);
    if (it != functionsMap.end()) {
        std::shared_ptr<Function> function = it->second;
        return function->doOperation(nargs, args);
    } else {
        throw(std::invalid_argument("funtion " + std::to_string((int) op) + " not present"));
    }
}

bool FunctionSet::inWorkingRange(Function::OperationType op, int nargs, va_list args) const throw(std::invalid_argument) {
    int castop = (int) op;

    auto it = functionsMap.find(castop);
    if (it != functionsMap.end()) {
        std::shared_ptr<Function> function = it->second;
        return function->inWorkingRange(nargs, args);
    } else {
        throw(std::invalid_argument("FunctionSet::inWorkingRange. Funtion " + std::to_string((int) op) + " not present"));
    }
}

const std::shared_ptr<const ComparableRangeInterface> FunctionSet::getComparableWorkingRange(Function::OperationType op) const
    throw(std::invalid_argument)
{
    int castop = (int) op;

    auto it = functionsMap.find(castop);
    if (it != functionsMap.end()) {
        std::shared_ptr<Function> function = it->second;
        return function->getComparableWorkingRange();
    } else {
        throw(std::invalid_argument("FunctionSet::getComparableWorkingRange. Funtion " + std::to_string((int) op) + " not present"));
    }
}

units::Volume FunctionSet::getMinVolume(Function::OperationType op) const throw(std::invalid_argument) {
    int castop = (int) op;

    auto it = functionsMap.find(castop);
    if (it != functionsMap.end()) {
        std::shared_ptr<Function> function = it->second;
        return function->getMinVolume();
    } else {
        throw(std::invalid_argument("FunctionSet::getMinVolume. Funtion " + std::to_string((int) op) + " not present"));
    }
}

void FunctionSet::addOperation(std::shared_ptr<Function> function) {
    int castop = (int) function->getAceptedOp();

    auto it = functionsMap.find(castop);
    if (it != functionsMap.end()) {
        it->second = function;
    } else {
        functionsMap.insert(std::make_pair(castop, function));
    }
    aceptedFunctions[castop] = 1;
}

void FunctionSet::setFactory(std::shared_ptr<PluginAbstractFactory> factory) {
    for (auto it : functionsMap) {
        it.second->setFactory(factory);
    }
}

void FunctionSet::setFactory(Function::OperationType op, std::shared_ptr<PluginAbstractFactory> factory) throw(std::invalid_argument) {
    int castop = (int) op;

    auto it = functionsMap.find(castop);
    if (it != functionsMap.end()) {
        std::shared_ptr<Function> function = it->second;
        function->setFactory(factory);
    } else {
        throw(std::invalid_argument("funtion " + std::to_string((int) op) + " not present"));
    }
}
