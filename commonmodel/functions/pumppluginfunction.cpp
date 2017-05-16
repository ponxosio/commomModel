#include "pumppluginfunction.h"

PumpPluginFunction::PumpPluginFunction(
        std::shared_ptr<PluginAbstractFactory> factory,
        const PluginConfiguration & configuration,
        const PumpWorkingRange & workingrange) :
    Function(factory)
{
    this->workingRange = std::make_shared<PumpWorkingRange>(workingrange);
    configurationObj = std::make_shared<PluginConfiguration>(configuration);
}

PumpPluginFunction::~PumpPluginFunction() {

}

Function::OperationType PumpPluginFunction::getAceptedOp() const {
    return pump;
}

bool PumpPluginFunction::inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument) {
    if (nargs == 1) {
        units::Volumetric_Flow rate = va_arg(args, units::Volumetric_Flow);
        return workingRange->inWorkingRange(rate);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of PumpPluginFunction must receive 1 arguments, received " + std::to_string(nargs)));
    }
}

const std::shared_ptr<const ComparableRangeInterface> PumpPluginFunction::getComparableWorkingRange() const {
    return workingRange;
}

std::shared_ptr<MultiUnitsWrapper> PumpPluginFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!pluginPump) {
        pluginPump = factory->makePump(configurationObj);
    }

    if (nargs == 2) { //start
        //va_start(args, nargs);
        int dir = va_arg(args, int);
        units::Volumetric_Flow rate = va_arg(args, units::Volumetric_Flow);
        pluginPump->setPumpState(dir, rate);
        //va_end(args);
        return NULL;
    } else if (nargs == 0) { //stop
        pluginPump->stopPump();
        return NULL;
    } else {
        throw(std::invalid_argument(" doOperation() of PumpPluginFunction must receive 2 or 0 arguments, received " + std::to_string(nargs)));
    }
}

units::Volume PumpPluginFunction::getMinVolume() const {
    return 0.0 * units::l;
}
