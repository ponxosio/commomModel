#include "measureodfunction.h"

MeasureOdFunction::MeasureOdFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        units::Volume minVolume) :
    Function(factory), configurationObj(configuration)
{
    this->minVolume = minVolume;
}

MeasureOdFunction::~MeasureOdFunction() {

}

Function::OperationType MeasureOdFunction::getAceptedOp() {
    return measure_od;
}

MultiUnitsWrapper* MeasureOdFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!odSensoPlugin) {
        odSensoPlugin = factory->makeOdSensor(configurationObj);
    }

    if (nargs == 0) {
        //va_start(args, nargs);
        //va_end(args);
        MultiUnitsWrapper* valueRead = new MultiUnitsWrapper();
        valueRead->setNoUnits(odSensoPlugin->measureOd());
        return valueRead;
    } else {
        throw(std::invalid_argument(" doOperation() of MeasureOdFunction must receive 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume MeasureOdFunction::getMinVolume() {
    return minVolume;
}
