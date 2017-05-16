#include "electrophoresisfunction.h"

ElectrophoresisFunction::ElectrophoresisFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume,
        const ElectrophoresisWorkingRange & workingRange) :
    Function(factory)
{
    this->minVolume = minVolume;
    this->workingRange = std::make_shared<ElectrophoresisWorkingRange>(workingRange);

    configurationObj = std::make_shared<PluginConfiguration>(configuration);
}

ElectrophoresisFunction::~ElectrophoresisFunction() {

}

Function::OperationType ElectrophoresisFunction::getAceptedOp() const {
    return electrophoresis;
}

bool ElectrophoresisFunction::inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument) {
    if (nargs == 1) {
        units::ElectricField eField = va_arg(args, units::ElectricField);
        return workingRange->inWorkingRange(eField);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of ElectrophoresisFunction must receive 1 argument, received " + std::to_string(nargs)));
    }
}

const std::shared_ptr<const ComparableRangeInterface> ElectrophoresisFunction::getComparableWorkingRange() const {
    return workingRange;
}

std::shared_ptr<MultiUnitsWrapper> ElectrophoresisFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!electrophoresisPlugin) {
        electrophoresisPlugin = factory->makeElectrophorer(configurationObj);
    }

    if (nargs == 1) { //start
        units::ElectricField eField = va_arg(args, units::ElectricField);
        electrophoresisPlugin->startElectrophoresis(eField);
        return NULL;
    } else if(nargs == 0) { //stop
        std::shared_ptr<MultiUnitsWrapper> valueReturned = std::make_shared<MultiUnitsWrapper>();
        valueReturned->setElectrophoresisResult(electrophoresisPlugin->stopElectrophpresis());
        return valueReturned;
    } else {
        throw(std::invalid_argument(" doOperation() of ElectrophoresisFunction must receive 1 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume ElectrophoresisFunction::getMinVolume() const {
    return minVolume;
}
