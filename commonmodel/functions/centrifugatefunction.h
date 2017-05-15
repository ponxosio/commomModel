#ifndef CENTRIFUGATEFUNCTION_H
#define CENTRIFUGATEFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/functions/function.h"
#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/centrifugatepluginproduct.h"

#include "commonmodel/commommodel_global.h"


class CentrifugateFunction : public Function
{
public:
    CentrifugateFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration, double minVolume);
    virtual ~CentrifugateFunction();

    virtual OperationType getAceptedOp();
    virtual bool inWorkingRange(int nargs, va_list args) throw(std::invalid_argument);
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual units::Volume getMinVolume();

protected:
    double minVolume;
    PluginConfiguration configurationObj;
    std::shared_ptr<CentrifugatePluginProduct> centrifugatePlugin;
};

#endif // CENTRIFUGATEFUNCTION_H
