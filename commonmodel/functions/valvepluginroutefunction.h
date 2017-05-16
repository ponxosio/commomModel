#ifndef VALVEPLUGINROUTEFUNCTION_H
#define VALVEPLUGINROUTEFUNCTION_H

#include <memory>

#include "commonmodel/functions/function.h"
#include "commonmodel/functions/ranges/emptyworkingrange.h"

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/valvepluginproduct.h"

#include "commonmodel/commommodel_global.h"

class VALVEPLUGINGROUTINGFUNCTION_EXPORT ValvePluginRouteFunction : public Function
{
public:
    ValvePluginRouteFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration);
    virtual ~ValvePluginRouteFunction();

    virtual OperationType getAceptedOp() const;
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw(std::invalid_argument);

    virtual bool inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument);
    virtual const std::shared_ptr<const ComparableRangeInterface> getComparableWorkingRange() const;

    virtual units::Volume getMinVolume() const;

protected:
    std::shared_ptr<EmptyWorkingRange> workingRange;
    std::shared_ptr<PluginConfiguration> configurationObj;
    std::shared_ptr<ValvePluginProduct> valvePlugin;
};

#endif // VALVEPLUGINROUTEFUNCTION_H
