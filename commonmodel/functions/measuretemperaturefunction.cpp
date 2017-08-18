#include "measuretemperaturefunction.h"

MeasureTemperatureFunction::MeasureTemperatureFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume) :
    Function(factory)
{
    this->minVolume = minVolume;

    configurationObj = std::make_shared<PluginConfiguration>(configuration);
    running = false;
}

MeasureTemperatureFunction::~MeasureTemperatureFunction() {

}

Function::OperationType MeasureTemperatureFunction::getAceptedOp() const {
    return Function::measure_temperature;
}

bool MeasureTemperatureFunction::inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument) {
    if (nargs == 0) {
        return true;
    } else {
        throw(std::invalid_argument(" inWorkingRange() of MeasureTemperatureFunction must receive 0 argument, received " + std::to_string(nargs)));
    }
}

const std::shared_ptr<const ComparableRangeInterface> MeasureTemperatureFunction::getComparableWorkingRange() const {
    return workingRange;
}

std::shared_ptr<MultiUnitsWrapper> MeasureTemperatureFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!temperatureSensorPlugin) {
        temperatureSensorPlugin = factory->makeTemperatureSensor(configurationObj);
    }

    if (nargs == 1) { //start measurement
        //va_start(args, nargs);
        //va_end(args);
        units::Frequency measurementFrequency = va_arg(args, units::Frequency);
        temperatureSensorPlugin->startMeasureTemperature(measurementFrequency);
        running = true;

        return NULL;
    } else if (nargs == 0) { //get measure value
        std::shared_ptr<MultiUnitsWrapper> valueRead = std::make_shared<MultiUnitsWrapper>();
        valueRead->setTemperature(temperatureSensorPlugin->getTemperatureMeasurement());
        running = false;

        return valueRead;
    } else {
        throw(std::invalid_argument(" doOperation() of MeasureTemperatureFunction must receive 1 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume MeasureTemperatureFunction::getMinVolume() const {
    return minVolume;
}

void MeasureTemperatureFunction::stopOperation() {
    if (running) {
        temperatureSensorPlugin->getTemperatureMeasurement();
        running = false;
    }
}
