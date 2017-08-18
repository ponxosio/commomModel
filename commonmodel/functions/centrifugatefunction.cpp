#include "centrifugatefunction.h"

CentrifugateFunction::CentrifugateFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume,
        const CentrifugationWorkingRange & workingRange) :
    Function(factory)
{
    this->minVolume = minVolume;
    this->workingRange = std::make_shared<CentrifugationWorkingRange>(workingRange);

    this->configurationObj = std::make_shared<PluginConfiguration>(configuration);

    this->running = false;
}

CentrifugateFunction::~CentrifugateFunction() {

}

Function::OperationType CentrifugateFunction::getAceptedOp() const {
    return centrifugate;
}

bool CentrifugateFunction::inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument) {
    if (nargs == 1) {
        units::Frequency intensity = va_arg(args, units::Frequency);
        return workingRange->inWorkingRange(intensity);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of CentrifugateFunction must receive 1 argument, received " + std::to_string(nargs)));
    }
}

const std::shared_ptr<const ComparableRangeInterface> CentrifugateFunction::getComparableWorkingRange() const {
    return workingRange;
}

std::shared_ptr<MultiUnitsWrapper> CentrifugateFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!centrifugatePlugin) {
        centrifugatePlugin = factory->makeCentrifugate(configurationObj);
    }

    if (nargs == 1) { //start
        units::Frequency intensity = va_arg(args, units::Frequency);
        centrifugatePlugin->startCentrifugate(intensity);
        this->running = true;
        return NULL;
    } else if(nargs == 0) { //stop
        centrifugatePlugin->turnOff();
        this->running = false;
        return NULL;
    } else {
        throw(std::invalid_argument(" doOperation() of CentrifugateFunction must receive 1 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume CentrifugateFunction::getMinVolume() const {
    return minVolume;
}

void CentrifugateFunction::stopOperation() {
    if (running) {
        centrifugatePlugin->turnOff();
        this->running = false;
    }
}
