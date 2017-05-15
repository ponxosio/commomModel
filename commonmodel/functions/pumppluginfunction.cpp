#include "pumppluginfunction.h"

PumpPluginFunction::PumpPluginFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration) :
    Function(factory), configurationObj(configuration)
{

}

PumpPluginFunction::~PumpPluginFunction() {

}

Function::OperationType PumpPluginFunction::getAceptedOp() {
    return pump;
}

bool PumpPluginFunction::inWorkingRange(int nargs, va_list args) throw(std::invalid_argument) {
    if (!pluginPump) {
        pluginPump = factory->makePump(configurationObj);
    }

    if (nargs == 1) {
        units::Volumetric_Flow rate = va_arg(args, units::Volumetric_Flow);
        return pluginPump->inWorkingRange(rate);
    } else {
        throw(std::invalid_argument(" inWorkingRange() of PumpPluginFunction must receive 1 arguments, received " + std::to_string(nargs)));
    }
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

units::Volume PumpPluginFunction::getMinVolume() {
    return 0.0;
}
