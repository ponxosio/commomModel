#include "stirfunction.h"

StirFunction::StirFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume,
        units::Frequency minIntensity,
        units::Frequency maxIntensity) :
    Function(factory)
{
    this->minVolume = minVolume;
    this->minIntensity = minIntensity;
    this->maxIntensity = maxIntensity;

    configurationObj = std::make_shared<PluginConfiguration>(configuration);
}

StirFunction::~StirFunction() {

}

Function::OperationType StirFunction::getAceptedOp() {
    return stir;
}

bool StirFunction::inWorkingRange(int nargs, va_list args) throw(std::invalid_argument) {
    if (nargs == 1) {
        units::Frequency intensity = va_arg(args, units::Frequency);
        return ((intensity >= minIntensity) && (intensity <= maxIntensity));
    } else {
        throw(std::invalid_argument(" inWorkingRange() of StirFunction must receive 1 argument, received " + std::to_string(nargs)));
    }
}

std::shared_ptr<MultiUnitsWrapper> StirFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!stirPlugin) {
        stirPlugin = factory->makeStirer(configurationObj);
    }

    if (nargs == 1) { //start
        //va_start(ap, args);
        units::Frequency intensity = va_arg(args, units::Frequency);
        stirPlugin->stir(intensity);
        //va_end(ap);
        return NULL;
    } else if(nargs == 0) { //stop
        stirPlugin->turnOff();
        return NULL;
    } else {
        throw(std::invalid_argument(" doOperation() of StirFunction must receive 1 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume StirFunction::getMinVolume() {
    return minVolume;
}
