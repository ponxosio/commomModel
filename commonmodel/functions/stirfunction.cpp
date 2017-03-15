#include "stirfunction.h"

StirFunction::StirFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration, double minVolume) :
    Function(factory), configurationObj(configuration)
{
    this->minVolume = minVolume;
}

StirFunction::~StirFunction() {

}

Function::OperationType StirFunction::getAceptedOp() {
    return stir;
}

MultiUnitsWrapper* StirFunction::doOperation(int nargs, va_list args) throw (std::invalid_argument) {
    if (!stirPlugin) {
        stirPlugin = factory->makeStirer(configurationObj);
    }

    if (nargs == 1) {
        //va_start(ap, args);
        units::Frequency intensity = va_arg(args, units::Frequency);
        stirPlugin->stir(intensity);
        //va_end(ap);
        return NULL;
    } else {
        throw(std::invalid_argument(" doOperation() of StirFunction must receive 1 argument, received " + std::to_string(nargs)));
    }
}

units::Volume StirFunction::getMinVolume() {
    return minVolume;
}
