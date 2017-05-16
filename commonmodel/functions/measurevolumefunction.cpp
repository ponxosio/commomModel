#include "measurevolumefunction.h"

MeasureVolumeFunction::MeasureVolumeFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume) :
    Function(factory)
{
    this->minVolume = minVolume;

    configurationObj = std::make_shared<PluginConfiguration>(configuration);
}

MeasureVolumeFunction::~MeasureVolumeFunction() {

}

Function::OperationType MeasureVolumeFunction::getAceptedOp() {
    return measure_volume;
}

bool MeasureVolumeFunction::inWorkingRange(int nargs, va_list args) throw(std::invalid_argument) {
    if (nargs == 0) {
        return true;
    } else {
        throw(std::invalid_argument(" inWorkingRange() of MeasureVolumeFunction must receive 0 argument, received " + std::to_string(nargs)));
    }
}

std::shared_ptr<MultiUnitsWrapper> MeasureVolumeFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!volumeSensorPlugin) {
        volumeSensorPlugin = factory->makeVolumeSensor(configurationObj);
    }

    if (nargs == 1) { //start measurement
        //va_start(args, nargs);
        //va_end(args);
        units::Frequency measurementFrequency = va_arg(args, units::Frequency);
        volumeSensorPlugin->startMeasureVolume(measurementFrequency);
        return NULL;
    } else if (nargs == 0) { //get measure value
        std::shared_ptr<MultiUnitsWrapper> valueRead = std::make_shared<MultiUnitsWrapper>();
        valueRead->setVolume(volumeSensorPlugin->getVolumeMeasurement());
        return valueRead;
    } else {
        throw(std::invalid_argument(" doOperation() of MeasureVolumeFunction must receive 1 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume MeasureVolumeFunction::getMinVolume() {
    return minVolume;
}
