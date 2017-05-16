#ifndef MEASUREODFUNCTION_H
#define MEASUREODFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/functions/function.h"
#include "commonmodel/functions/ranges/measureodworkingrange.h"

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/odsensorpluginproduct.h"

#include "commonmodel/commommodel_global.h"

class MEASUREOD_EXPORT MeasureOdFunction : public Function
{
public:
    MeasureOdFunction(std::shared_ptr<PluginAbstractFactory> factory,
                      const PluginConfiguration & configuration,
                      units::Volume minVolume,
                      const MeasureOdWorkingRange & workingRange);
    virtual ~MeasureOdFunction();

    virtual OperationType getAceptedOp() const;
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);

    virtual bool inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument);
    virtual const std::shared_ptr<const ComparableRangeInterface> getComparableWorkingRange() const;

    virtual units::Volume getMinVolume() const;

protected:
    units::Volume minVolume;
    std::shared_ptr<MeasureOdWorkingRange> workingRange;

    std::shared_ptr<PluginConfiguration> configurationObj;
    std::shared_ptr<OdSensorPluginProduct> odSensoPlugin;
};

#endif // MEASUREODFUNCTION_H
