#ifndef MEASUREODFUNCTION_H
#define MEASUREODFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/odsensorpluginproduct.h"
#include "commonmodel/functions/function.h"

class MeasureOdFunction : public Function
{
public:
    MeasureOdFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration, double minVolume);
    virtual ~MeasureOdFunction();

    virtual OperationType getAceptedOp();
    virtual double doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual double getMinVolume();

protected:
    double minVolume;
    PluginConfiguration configurationObj;
    std::shared_ptr<OdSensorPluginProduct> odSensoPlugin;
};

#endif // MEASUREODFUNCTION_H
