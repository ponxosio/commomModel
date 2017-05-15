#ifndef MEASUREODFUNCTION_H
#define MEASUREODFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/odsensorpluginproduct.h"
#include "commonmodel/functions/function.h"

#include "commonmodel/commommodel_global.h"

class MEASUREOD_EXPORT MeasureOdFunction : public Function
{
public:
    MeasureOdFunction(std::shared_ptr<PluginAbstractFactory> factory,
                      const PluginConfiguration & configuration,
                      units::Volume minVolume,
                      units::Length minWavelength,
                      units::Length maxWavelength);
    virtual ~MeasureOdFunction();

    virtual OperationType getAceptedOp();
    virtual bool inWorkingRange(int nargs, va_list args) throw(std::invalid_argument);
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual units::Volume getMinVolume();

protected:
    units::Volume minVolume;
    units::Length minWavelength;
    units::Length maxWavelength;

    std::shared_ptr<PluginConfiguration> configurationObj;
    std::shared_ptr<OdSensorPluginProduct> odSensoPlugin;
};

#endif // MEASUREODFUNCTION_H
