#ifndef MEASURETEMPERATUREFUNCTION_H
#define MEASURETEMPERATUREFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/functions/function.h"
#include "commonmodel/functions/ranges/emptyworkingrange.h"

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/temperaturesensorproduct.h"

#include "commonmodel/commommodel_global.h"

class MEASURETEMPERATUREFUNCTION_EXPORT MeasureTemperatureFunction : public Function
{
public:
    MeasureTemperatureFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration, units::Volume minVolume);
    virtual ~MeasureTemperatureFunction();

    virtual OperationType getAceptedOp() const;
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);

    virtual bool inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument);
    virtual const std::shared_ptr<const ComparableRangeInterface> getComparableWorkingRange() const;

    virtual units::Volume getMinVolume() const;

    virtual void stopOperation();

protected:
    bool running;
    units::Volume minVolume;
    std::shared_ptr<EmptyWorkingRange> workingRange;

    std::shared_ptr<PluginConfiguration> configurationObj;
    std::shared_ptr<TemperatureSensorProduct> temperatureSensorPlugin;
};

#endif // MEASURETEMPERATUREFUNCTION_H
