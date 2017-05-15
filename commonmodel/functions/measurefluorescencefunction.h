#ifndef MEASUREFLUORESCENCEFUNCTION_H
#define MEASUREFLUORESCENCEFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/fluorescencesensorproduct.h"
#include "commonmodel/functions/function.h"

#include "commonmodel/commommodel_global.h"

class MeasureFluorescenceFunction : public Function
{
public:
    MeasureFluorescenceFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration, double minVolume);
    virtual ~MeasureFluorescenceFunction();

    virtual OperationType getAceptedOp();
    virtual bool inWorkingRange(int nargs, va_list args) throw(std::invalid_argument);
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual units::Volume getMinVolume();

protected:
    double minVolume;
    PluginConfiguration configurationObj;
    std::shared_ptr<FluorescenceSensorProduct> fluorescenceSensoPlugin;
};

#endif // MEASUREFLUORESCENCEFUNCTION_H
