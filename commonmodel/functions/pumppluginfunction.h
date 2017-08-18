#ifndef PUMPPLUGINFUNCTION_H
#define PUMPPLUGINFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/functions/function.h"
#include "commonmodel/functions/ranges/pumpworkingrange.h"

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/pumppluginproduct.h"

#include "commonmodel/commommodel_global.h"

class PUMPPLUGINFUNCTION_EXPORT PumpPluginFunction : public Function
{
public:
    PumpPluginFunction(std::shared_ptr<PluginAbstractFactory> factory,
                       const PluginConfiguration & configuration,
                       const PumpWorkingRange & workingrange);
    virtual ~PumpPluginFunction();

    virtual OperationType getAceptedOp() const;
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);

    virtual bool inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument);
    virtual const std::shared_ptr<const ComparableRangeInterface> getComparableWorkingRange() const;

    virtual units::Volume getMinVolume() const;

    virtual void stopOperation();

protected:
    bool running;
    std::shared_ptr<PumpWorkingRange> workingRange;

    std::shared_ptr<PluginConfiguration> configurationObj;
    std::shared_ptr<PumpPluginProduct> pluginPump;

};

#endif // PUMPPLUGINFUNCTION_H
