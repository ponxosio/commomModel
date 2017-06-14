#include "lightfunction.h"

LightFunction::LightFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume,
        const LigthWorkingRange & workingRange) :
    Function(factory)
{
    this->minVolume = minVolume;
    this->workingRange = std::make_shared<LigthWorkingRange>(workingRange);

    configurationObj = std::make_shared<PluginConfiguration>(configuration);
}

LightFunction::~LightFunction() {

}

Function::OperationType LightFunction::getAceptedOp() const {
    return apply_light;
}

bool LightFunction::inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument) {
    if (nargs == 2) {
        units::LuminousIntensity intensity = va_arg(args, units::LuminousIntensity);
        units::Length wavelength = va_arg(args, units::Length);

        return workingRange->inWorkingRange(wavelength, intensity);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of LightFunction must receive 2 argument, received " + std::to_string(nargs)));
    }
}

const std::shared_ptr<const ComparableRangeInterface> LightFunction::getComparableWorkingRange() const {
    return workingRange;
}

std::shared_ptr<MultiUnitsWrapper> LightFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!lightPlugin) {
        lightPlugin = factory->makeLight(configurationObj);
    }

    if (nargs == 2) { //start
        //va_start(ap, args);
        units::LuminousIntensity intensity = va_arg(args, units::LuminousIntensity);
        units::Length wavelength = va_arg(args, units::Length);
        lightPlugin->applyLight(intensity, wavelength);
        //va_end(ap);
        return NULL;
    } else if (nargs == 0) { //stop
        lightPlugin->turnOffLight();
        return NULL;
    } else {
        throw(std::invalid_argument(" doOperation() of LightFunction must receive 2 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume LightFunction::getMinVolume() const {
    return minVolume;
}
