#ifndef SHAKEFUNCTION_H
#define SHAKEFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/functions/function.h"
#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/shakepluginproduct.h"

#include "commonmodel/commommodel_global.h"

class ShakeFunction : public Function
{
public:
    ShakeFunction(std::shared_ptr<PluginAbstractFactory> factory,
                  const PluginConfiguration & configuration,
                  units::Volume minVolume,
                  units::Frequency minIntensity,
                  units::Frequency maxIntensity);
    virtual ~ShakeFunction();

    virtual OperationType getAceptedOp();
    virtual bool inWorkingRange(int nargs, va_list args) throw(std::invalid_argument);
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual units::Volume getMinVolume();

protected:
    units::Volume minVolume;
    units::Frequency minIntensity;
    units::Frequency maxIntensity;

    std::shared_ptr<PluginConfiguration> configurationObj;
    std::shared_ptr<ShakePluginProduct> shakePlugin;
};

#endif // SHAKEFUNCTION_H
