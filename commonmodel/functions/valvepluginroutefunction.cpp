#include "valvepluginroutefunction.h"

ValvePluginRouteFunction::ValvePluginRouteFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration) :
    Function(factory), configurationObj(configuration)
{

}

ValvePluginRouteFunction::~ValvePluginRouteFunction() {

}

Function::OperationType ValvePluginRouteFunction::getAceptedOp() {
    return route;
}

MultiUnitsWrapper* ValvePluginRouteFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!valvePlugin) {
        valvePlugin = factory->makeValve(configurationObj);
    }

    if (nargs == 1) {
        //va_start(args, nargs);
        int newPosition = va_arg(args, int);
        valvePlugin->moveToPosition(newPosition);
        //va_end(args);
        return NULL;
    } else {
        throw(std::invalid_argument(" doOperation() of ValvePLuginRouteFunction must receive 1 argument, received " + std::to_string(nargs)));
    }
}

units::Volume ValvePluginRouteFunction::getMinVolume() {
    return 0.0;
}

