#ifndef PUMPPLUGINFUNCTION_H
#define PUMPPLUGINFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/functions/function.h"
#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/pumppluginproduct.h"

#include "commonmodel/commommodel_global.h"

class PUMPPLUGINFUNCTION_EXPORT PumpPluginFunction : public Function
{
public:
    PumpPluginFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration);
    virtual ~PumpPluginFunction();

    virtual OperationType getAceptedOp();
    virtual double doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual double getMinVolume();

protected:
    PluginConfiguration configurationObj;
    std::shared_ptr<PumpPluginProduct> pluginPump;

};

#endif // PUMPPLUGINFUNCTION_H
