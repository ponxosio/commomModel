#include "measureluminiscencefunction.h"

MeasureLuminiscenceFunction::MeasureLuminiscenceFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume) :
    Function(factory)
{
    this->minVolume = minVolume;

    workingRange = std::make_shared<EmptyWorkingRange>();
    configurationObj = std::make_shared<PluginConfiguration>(configuration);
    running = false;
}

MeasureLuminiscenceFunction::~MeasureLuminiscenceFunction() {

}

Function::OperationType MeasureLuminiscenceFunction::getAceptedOp() const {
    return measure_luminiscence;
}

bool MeasureLuminiscenceFunction::inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument) {
    if (nargs == 0) {
        return true;
    } else {
        throw(std::invalid_argument(" inWorkingRange() of MeasureLuminiscenceFunction must receive 0 argument, received " + std::to_string(nargs)));
    }
}

const std::shared_ptr<const ComparableRangeInterface> MeasureLuminiscenceFunction::getComparableWorkingRange() const {
    return workingRange;
}

std::shared_ptr<MultiUnitsWrapper> MeasureLuminiscenceFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!luminiscenceSensoPlugin) {
        luminiscenceSensoPlugin = factory->makeLuminiscenseSensor(configurationObj);
    }

    if (nargs == 1) { //start measurement
        //va_start(args, nargs);
        //va_end(args);
        units::Frequency measurementFrequency = va_arg(args, units::Frequency);
        luminiscenceSensoPlugin->startMeasureLuminiscence(measurementFrequency);
        running = true;
        return NULL;
    } else if (nargs == 0) { //get measure value
        std::shared_ptr<MultiUnitsWrapper> valueRead = std::make_shared<MultiUnitsWrapper>();
        valueRead->setLuminousIntensity(luminiscenceSensoPlugin->getLuminiscenceMeasurement());
        running = false;
        return valueRead;
    } else {
        throw(std::invalid_argument(" doOperation() of MeasureLuminiscenceFunction must receive 1 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume MeasureLuminiscenceFunction::getMinVolume() const {
    return minVolume;
}

void MeasureLuminiscenceFunction::stopOperation() {
    if (running) {
        luminiscenceSensoPlugin->getLuminiscenceMeasurement();
        running = false;
    }
}
