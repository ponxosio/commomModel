#ifndef VALVEPLUGINROUTEFUNCTION_H
#define VALVEPLUGINROUTEFUNCTION_H

#include <memory>

#include "commonmodel/functions/function.h"
#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/valvepluginproduct.h"

#include "commonmodel/commommodel_global.h"

class VALVEPLUGINGROUTINGFUNCTION_EXPORT ValvePluginRouteFunction : public Function
{
public:
    ValvePluginRouteFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration);
    virtual ~ValvePluginRouteFunction();

    virtual OperationType getAceptedOp();
    virtual double doOperation(int nargs, va_list args) throw(std::invalid_argument);
    virtual double getMinVolume();

protected:
    PluginConfiguration configurationObj;
    std::shared_ptr<ValvePluginProduct> valvePlugin;
};

#endif // VALVEPLUGINROUTEFUNCTION_H
