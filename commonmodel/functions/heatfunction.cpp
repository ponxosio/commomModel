#include "heatfunction.h"

HeatFunction::HeatFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume,
        units::Temperature minTemperature,
        units::Temperature maxTemperature) :
    Function(factory)
{
    this->minVolume = minVolume;
    this->minTemperature = minTemperature;
    this->maxTemperature = maxTemperature;

    configurationObj = std::make_shared<PluginConfiguration>(configuration);
}

HeatFunction::~HeatFunction() {

}

Function::OperationType HeatFunction::getAceptedOp() {
    return heat;
}

bool HeatFunction::inWorkingRange(int nargs, va_list args) throw(std::invalid_argument) {
    if (nargs == 1) {
        units::Temperature temperature = va_arg(args, units::Temperature);
        return ((temperature >= minTemperature) && (temperature <= maxTemperature));
    } else {
        throw(std::invalid_argument(" inWorkingRange() of HeatFunction must receive 1 argument, received " + std::to_string(nargs)));
    }
}

std::shared_ptr<MultiUnitsWrapper> HeatFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!heaterPlugin) {
        heaterPlugin = factory->makeHeater(configurationObj);
    }

    if (nargs == 1) { //start
        //va_start(ap, args);
        units::Temperature temperature = va_arg(args, units::Temperature);
        heaterPlugin->changeTemperature(temperature);
        //va_end(ap);
        return NULL;
    } else if (nargs == 0) { //turn off
        heaterPlugin->turnOff();
        //va_end(ap);
        return NULL;
    } else {
        throw(std::invalid_argument(" doOperation() of HeatFunction must receive 1 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume HeatFunction::getMinVolume() {
    return minVolume;
}
