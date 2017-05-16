#include "valvepluginroutefunction.h"

ValvePluginRouteFunction::ValvePluginRouteFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration) :
    Function(factory)
{
    workingRange = std::make_shared<EmptyWorkingRange>();
    configurationObj = std::make_shared<PluginConfiguration>(configuration);
}

ValvePluginRouteFunction::~ValvePluginRouteFunction() {

}

Function::OperationType ValvePluginRouteFunction::getAceptedOp() const {
    return route;
}

bool ValvePluginRouteFunction::inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument) {
    if (nargs == 0) {
        return true;
    } else {
        throw(std::invalid_argument(" inWorkingRange() of ValvePLuginRouteFunction must receive 0 argument, received " + std::to_string(nargs)));
    }
}

const std::shared_ptr<const ComparableRangeInterface> ValvePluginRouteFunction::getComparableWorkingRange() const {
    return workingRange;
}

std::shared_ptr<MultiUnitsWrapper> ValvePluginRouteFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!valvePlugin) {
        valvePlugin = factory->makeValve(configurationObj);
    }

    if (nargs == 1) { //move valve
        //va_start(args, nargs);
        int newPosition = va_arg(args, int);
        valvePlugin->moveToPosition(newPosition);
        //va_end(args);
        return NULL;
    } else if (nargs == 0) { //close valve
        valvePlugin->closeValve();
        return NULL;
    } else {
        throw(std::invalid_argument(" doOperation() of ValvePLuginRouteFunction must receive 1 or 0 argument, received " + std::to_string(nargs)));
    }
}

units::Volume ValvePluginRouteFunction::getMinVolume() const {
    return 0.0 * units::l;
}

