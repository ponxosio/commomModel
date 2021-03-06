#include "stirfunction.h"

StirFunction::StirFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume,
        const StirWorkingRange & workingRange) :
    Function(factory)
{
    this->minVolume = minVolume;
    this->workingRange = std::make_shared<StirWorkingRange>(workingRange);
    configurationObj = std::make_shared<PluginConfiguration>(configuration);
    running = false;
}

StirFunction::~StirFunction() {

}

Function::OperationType StirFunction::getAceptedOp() const {
    return stir;
}

bool StirFunction::inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument) {
    if (nargs == 1) {
        units::Frequency intensity = va_arg(args, units::Frequency);
        return workingRange->inWorkingRange(intensity);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of StirFunction must receive 1 argument, received " + std::to_string(nargs)));
    }
}

const std::shared_ptr<const ComparableRangeInterface> StirFunction::getComparableWorkingRange() const {
    return workingRange;
}

std::shared_ptr<MultiUnitsWrapper> StirFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!stirPlugin) {
        stirPlugin = factory->makeStirer(configurationObj);
    }

    if (nargs == 1) { //start
        //va_start(ap, args);
        units::Frequency intensity = va_arg(args, units::Frequency);
        stirPlugin->stir(intensity);
        running = true;
        //va_end(ap);
        return NULL;
    } else if(nargs == 0) { //stop
        stirPlugin->turnOff();
        running = false;
        return NULL;
    } else {
        throw(std::invalid_argument(" doOperation() of StirFunction must receive 1 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume StirFunction::getMinVolume() const {
    return minVolume;
}

void StirFunction::stopOperation() {
    if (running) {
        stirPlugin->turnOff();
        running = false;
    }
}
