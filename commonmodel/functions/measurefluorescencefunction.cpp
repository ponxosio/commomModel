#include "measurefluorescencefunction.h"

MeasureFluorescenceFunction::MeasureFluorescenceFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        double minVolume) :
    configurationObj(configuration)
{
    this->factory = factory;
    this->minVolume = minVolume;
}

MeasureFluorescenceFunction::~MeasureFluorescenceFunction() {

}

Function::OperationType MeasureFluorescenceFunction::getAceptedOp() {
    return measure_fluorescence;
}

bool MeasureFluorescenceFunction::inWorkingRange(int nargs, va_list args) throw(std::invalid_argument) {
    if (!fluorescenceSensoPlugin) {
        fluorescenceSensoPlugin = factory->makeFluorescenceSensor(configurationObj);
    }

    if (nargs == 2) {
        units::Length excitation = va_arg(args, units::Length);
        units::Length emission = va_arg(args, units::Length);

        return fluorescenceSensoPlugin->inWorkingRange(excitation, emission);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of MeasureFluorescenceFunction must receive 2 argument, received " + std::to_string(nargs)));
    }
}

std::shared_ptr<MultiUnitsWrapper> MeasureFluorescenceFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!fluorescenceSensoPlugin) {
        fluorescenceSensoPlugin = factory->makeFluorescenceSensor(configurationObj);
    }

    if (nargs == 3) { //startMeasurement
        //va_start(args, nargs);
        //va_end(args);
        units::Frequency measurementFrequency = va_arg(args, units::Frequency);
        units::Length excitation = va_arg(args, units::Length);
        units::Length emission = va_arg(args, units::Length);

        fluorescenceSensoPlugin->startMeasureFluorescence(measurementFrequency, excitation, emission);
        return NULL;
    } else if (nargs == 0) { //return measure value
        std::shared_ptr<MultiUnitsWrapper> valueRead = std::make_shared<MultiUnitsWrapper>();
        valueRead->setLuminousIntensity(fluorescenceSensoPlugin->getFluorescenceMeasurement());

        return valueRead;
    } else {
        throw(std::invalid_argument(" doOperation() of MeasureFluorescenceFunction must receive 3 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume MeasureFluorescenceFunction::getMinVolume() {
    return minVolume;
}
