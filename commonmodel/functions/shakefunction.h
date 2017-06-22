#ifndef SHAKEFUNCTION_H
#define SHAKEFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/functions/function.h"
#include "commonmodel/functions/ranges/shakeworkingrange.h"

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/shakepluginproduct.h"

#include "commonmodel/commommodel_global.h"

class SHAKEFUNCTION_EXPORT ShakeFunction : public Function
{
public:
    ShakeFunction(std::shared_ptr<PluginAbstractFactory> factory,
                  const PluginConfiguration & configuration,
                  units::Volume minVolume,
                  const ShakeWorkingRange & workingRange);
    virtual ~ShakeFunction();

    virtual OperationType getAceptedOp() const;
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);

    virtual bool inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument);
    virtual const std::shared_ptr<const ComparableRangeInterface> getComparableWorkingRange() const;

    virtual units::Volume getMinVolume() const;

protected:
    units::Volume minVolume;
    std::shared_ptr<ShakeWorkingRange> workingRange;

    std::shared_ptr<PluginConfiguration> configurationObj;
    std::shared_ptr<ShakePluginProduct> shakePlugin;
};

#endif // SHAKEFUNCTION_H
