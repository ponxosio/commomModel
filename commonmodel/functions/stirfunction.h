#ifndef STIRFUNCTION_H
#define STIRFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/functions/function.h"
#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/stirerpluginproduct.h"

class StirFunction : public Function
{
public:
    StirFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration, double minVolume);
    virtual ~StirFunction();

    virtual OperationType getAceptedOp();
    virtual double doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual double getMinVolume();

protected:
    double minVolume;
    PluginConfiguration configurationObj;
    std::shared_ptr<StirerPluginProduct> stirPlugin;
};

#endif // STIRFUNCTION_H
