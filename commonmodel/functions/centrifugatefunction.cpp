#include "centrifugatefunction.h"

CentrifugateFunction::CentrifugateFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        double minVolume) :
    configurationObj(configuration)
{
    this->factory = factory;
    this->minVolume = minVolume;
}

CentrifugateFunction::~CentrifugateFunction() {

}

Function::OperationType CentrifugateFunction::getAceptedOp() {
    return centrifugate;
}

bool CentrifugateFunction::inWorkingRange(int nargs, va_list args) throw(std::invalid_argument) {
    if (!centrifugatePlugin) {
        centrifugatePlugin = factory->makeCentrifugate(configurationObj);
    }

    if (nargs == 1) {
        units::Frequency intensity = va_arg(args, units::Frequency);
        return centrifugatePlugin->inWorkingRange(intensity);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of CentrifugateFunction must receive 1 argument, received " + std::to_string(nargs)));
    }
}

std::shared_ptr<MultiUnitsWrapper> CentrifugateFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!centrifugatePlugin) {
        centrifugatePlugin = factory->makeCentrifugate(configurationObj);
    }

    if (nargs == 1) { //start
        units::Frequency intensity = va_arg(args, units::Frequency);
        centrifugatePlugin->startCentrifugate(intensity);
        return NULL;
    } else if(nargs == 0) { //stop
        centrifugatePlugin->stopShake();
        return NULL;
    } else {
        throw(std::invalid_argument(" doOperation() of CentrifugateFunction must receive 1 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume CentrifugateFunction::getMinVolume() {
    return minVolume;
}
