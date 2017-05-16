#include "measureodfunction.h"

MeasureOdFunction::MeasureOdFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume,
        const MeasureOdWorkingRange & workingRange) :
    Function(factory)
{
    this->minVolume = minVolume;
    this->workingRange = std::make_shared<MeasureOdWorkingRange>(workingRange);
    configurationObj = std::make_shared<PluginConfiguration>(configuration);
}

MeasureOdFunction::~MeasureOdFunction() {

}

Function::OperationType MeasureOdFunction::getAceptedOp() const {
    return measure_od;
}

bool MeasureOdFunction::inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument) {
    if (nargs == 1) {
        units::Length wavelength = va_arg(args, units::Length);
        return workingRange->inWorkingRange(wavelength);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of MeasureOdFunction must receive 1 argument, received " + std::to_string(nargs)));
    }
}

const std::shared_ptr<const ComparableRangeInterface> MeasureOdFunction::getComparableWorkingRange() const {
    return workingRange;
}

std::shared_ptr<MultiUnitsWrapper> MeasureOdFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!odSensoPlugin) {
        odSensoPlugin = factory->makeOdSensor(configurationObj);
    }

    if (nargs == 2) { //startMeasurement
        //va_start(args, nargs);
        //va_end(args);
        units::Frequency measurementFrequency = va_arg(args, units::Frequency);
        units::Length wavelength = va_arg(args, units::Length);
        odSensoPlugin->startMeasureOd(measurementFrequency, wavelength);

        return NULL;
    } else if (nargs == 0) { //returnMeasurement
        std::shared_ptr<MultiUnitsWrapper> valueRead = std::make_shared<MultiUnitsWrapper>();
        valueRead->setNoUnits(odSensoPlugin->getOdMeasurement());

        return valueRead;
    } else {
        throw(std::invalid_argument(" doOperation() of MeasureOdFunction must receive 2 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume MeasureOdFunction::getMinVolume() const {
    return minVolume;
}
