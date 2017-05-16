#include "shakefunction.h"

ShakeFunction::ShakeFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume,
        const ShakeWorkingRange & workingRange) :
    Function(factory)
{
    this->minVolume = minVolume;
    this->workingRange = std::make_shared<ShakeWorkingRange>(workingRange);
    configurationObj = std::make_shared<PluginConfiguration>(configuration);
}

ShakeFunction::~ShakeFunction() {

}

Function::OperationType ShakeFunction::getAceptedOp() const {
    return shake;
}

bool ShakeFunction::inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument) {
    if (nargs == 1) {
        units::Frequency intensity = va_arg(args, units::Frequency);
        return workingRange->inWorkingRange(intensity);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of ShakePluginFunction must receive 1 argument, received " + std::to_string(nargs)));
    }
}

const std::shared_ptr<const ComparableRangeInterface> ShakeFunction::getComparableWorkingRange() const {
    return workingRange;
}

std::shared_ptr<MultiUnitsWrapper> ShakeFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!shakePlugin) {
        shakePlugin = factory->makeShaker(configurationObj);
    }

    if (nargs == 1) {
        units::Frequency intensity = va_arg(args, units::Frequency);
        shakePlugin->startShake(intensity);
        return NULL;
    } else if(nargs == 0) { //stop
        shakePlugin->stopShake();
        return NULL;
    } else {
        throw(std::invalid_argument(" doOperation() of ShakePluginFunction must receive 1 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume ShakeFunction::getMinVolume() const {
    return minVolume;
}
