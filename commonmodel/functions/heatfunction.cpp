#include "heatfunction.h"

HeatFunction::HeatFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume,
        const HeaterWorkingRange & workingRange) :
    Function(factory)
{
    this->minVolume = minVolume;
    this->workingRange = std::make_shared<HeaterWorkingRange>(workingRange);
    configurationObj = std::make_shared<PluginConfiguration>(configuration);

    this->running = false;
}

HeatFunction::~HeatFunction() {

}

Function::OperationType HeatFunction::getAceptedOp() const {
    return heat;
}

bool HeatFunction::inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument) {
    if (nargs == 1) {
        units::Temperature temperature = va_arg(args, units::Temperature);
        return workingRange->inWorkingRange(temperature);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of HeatFunction must receive 1 argument, received " + std::to_string(nargs)));
    }
}

const std::shared_ptr<const ComparableRangeInterface> HeatFunction::getComparableWorkingRange() const {
    return workingRange;
}

std::shared_ptr<MultiUnitsWrapper> HeatFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!heaterPlugin) {
        heaterPlugin = factory->makeHeater(configurationObj);
    }

    if (nargs == 1) { //start
        //va_start(ap, args);
        units::Temperature temperature = va_arg(args, units::Temperature);
        heaterPlugin->changeTemperature(temperature);
        this->running = true;
        //va_end(ap);
        return NULL;
    } else if (nargs == 0) { //turn off
        heaterPlugin->turnOff();
        this->running = false;
        //va_end(ap);
        return NULL;
    } else {
        throw(std::invalid_argument(" doOperation() of HeatFunction must receive 1 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume HeatFunction::getMinVolume() const {
    return minVolume;
}

void HeatFunction::stopOperation() {
    if(running) {
        heaterPlugin->turnOff();
        this->running = false;
    }
}
