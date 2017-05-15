#include "shakefunction.h"

ShakeFunction::ShakeFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        double minVolume) :
    configurationObj(configuration)
{
    this->factory = factory;
    this->minVolume = minVolume;
}

ShakeFunction::~ShakeFunction() {

}

Function::OperationType ShakeFunction::getAceptedOp() {
    return shake;
}

bool ShakeFunction::inWorkingRange(int nargs, va_list args) throw(std::invalid_argument) {
    if (!shakePlugin) {
        shakePlugin = factory->makeShaker(configurationObj);
    }

    if (nargs == 1) {
        units::Frequency intensity = va_arg(args, units::Frequency);
        return shakePlugin->inWorkingRange(intensity);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of ShakePluginFunction must receive 1 argument, received " + std::to_string(nargs)));
    }
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

units::Volume ShakeFunction::getMinVolume() {
    return minVolume;
}
