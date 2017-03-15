#ifndef LIGHTFUNCTION_H
#define LIGHTFUNCTION_H

#include <memory>
#include <cstdarg>

#include <utils/units.h>

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/lightpluginproduct.h"
#include "commonmodel/functions/function.h"

#include "commonmodel/commommodel_global.h"

class LIGHTFUNCTION_EXPORT LightFunction : public Function
{
public:
    LightFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration, double minVolume);
    virtual ~LightFunction();

    virtual OperationType getAceptedOp();
    virtual MultiUnitsWrapper* doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual units::Volume getMinVolume();

protected:
    double minVolume;
    PluginConfiguration configurationObj;
    std::shared_ptr<LightPluginProduct> lightPlugin;
};

#endif // LIGHTFUNCTION_H
