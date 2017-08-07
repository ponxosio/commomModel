#ifndef LIGHTFUNCTION_H
#define LIGHTFUNCTION_H

#include <memory>
#include <cstdarg>

#include <utils/units.h>

#include "commonmodel/functions/function.h"
#include "commonmodel/functions/ranges/ligthworkingrange.h"

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/lightpluginproduct.h"

#include "commonmodel/commommodel_global.h"

class LIGHTFUNCTION_EXPORT LightFunction : public Function
{
public:
    LightFunction(std::shared_ptr<PluginAbstractFactory> factory,
                  const PluginConfiguration & configuration,
                  units::Volume minVolume,
                  const LigthWorkingRange & workingRange);
    virtual ~LightFunction();

    virtual OperationType getAceptedOp() const;
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);

    virtual bool inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument);
    virtual const std::shared_ptr<const ComparableRangeInterface> getComparableWorkingRange() const;

    virtual units::Volume getMinVolume() const;

    virtual void stopOperation();

protected:
    bool running;
    units::Volume minVolume;
    std::shared_ptr<LigthWorkingRange> workingRange;

    std::shared_ptr<PluginConfiguration> configurationObj;
    std::shared_ptr<LightPluginProduct> lightPlugin;
};

#endif // LIGHTFUNCTION_H
