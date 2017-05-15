#ifndef HEATFUNCTION_H
#define HEATFUNCTION_H

#include <memory>
#include <cstdarg>

#include <utils/units.h>

#include "commonmodel/functions/function.h"
#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/heaterpluginproduct.h"

#include "commonmodel/commommodel_global.h"

class HEATFUNCTION_EXPORT HeatFunction : public Function
{
public:
    HeatFunction(std::shared_ptr<PluginAbstractFactory> factory,
                 const PluginConfiguration & configuration,
                 units::Volume minVolume,
                 units::Temperature minTemperature,
                 units::Temperature maxTemperature);
    virtual ~HeatFunction();

    virtual OperationType getAceptedOp();
    virtual bool inWorkingRange(int nargs, va_list args) throw(std::invalid_argument);
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual units::Volume getMinVolume();

protected:
    units::Volume minVolume;
    units::Temperature minTemperature;
    units::Temperature maxTemperature;

    std::shared_ptr<PluginConfiguration> configurationObj;
    std::shared_ptr<HeaterPluginProduct> heaterPlugin;
};

#endif // HEATFUNCTION_H
