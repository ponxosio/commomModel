#include "lightfunction.h"

LightFunction::LightFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration, double minVolume) :
    Function(factory) , configurationObj(configuration)
{
    this->minVolume = minVolume;
}

LightFunction::~LightFunction() {

}

Function::OperationType LightFunction::getAceptedOp() {
    return apply_light;
}

bool LightFunction::inWorkingRange(int nargs, va_list args) throw(std::invalid_argument) {
    if (!lightPlugin) {
        lightPlugin = factory->makeLight(configurationObj);
    }

    if (nargs == 2) {
        units::LuminousIntensity intensity = va_arg(args, units::LuminousIntensity);
        units::Length wavelength = va_arg(args, units::Length);

        return lightPlugin->inWorkingRange(intensity, wavelength);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of LightFunction must receive 2 argument, received " + std::to_string(nargs)));
    }
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

units::Volume LightFunction::getMinVolume() {
    return minVolume;
}
