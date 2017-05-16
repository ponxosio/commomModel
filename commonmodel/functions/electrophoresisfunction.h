#ifndef ELECTROPHORESISFUNCTION_H
#define ELECTROPHORESISFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/functions/function.h"
#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/centrifugatepluginproduct.h"

#include "commonmodel/commommodel_global.h"

class ElectrophoresisFunction : public Function
{
public:
    ElectrophoresisFunction(std::shared_ptr<PluginAbstractFactory> factory,
                            const PluginConfiguration & configuration,
                            units::Volume minVolume,
                            units::ElectricField minEField,
                            units::ElectricField maxEField);
    virtual ~ElectrophoresisFunction();

    virtual OperationType getAceptedOp();
    virtual bool inWorkingRange(int nargs, va_list args) throw(std::invalid_argument);
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual units::Volume getMinVolume();

protected:
    units::Volume minVolume;
    units::ElectricField minEField;
    units::ElectricField maxEField;

    std::shared_ptr<PluginConfiguration> configurationObj;
    std::shared_ptr<ElectrophoresisPluginProduct> electrophoresisPlugin;
};

#endif // ELECTROPHORESISFUNCTION_H
