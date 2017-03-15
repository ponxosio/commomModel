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
    HeatFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration, double minVolume);
    virtual ~HeatFunction();

    virtual OperationType getAceptedOp();
    virtual MultiUnitsWrapper* doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual units::Volume getMinVolume();

protected:
    double minVolume;
    PluginConfiguration configurationObj;
    std::shared_ptr<HeaterPluginProduct> heaterPlugin;
};

#endif // HEATFUNCTION_H
