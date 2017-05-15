#ifndef MEASUREVOLUMEFUNCTION_H
#define MEASUREVOLUMEFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/volumesensorproduct.h"
#include "commonmodel/functions/function.h"

#include "commonmodel/commommodel_global.h"

class MeasureVolumeFunction : public Function
{
public:
    MeasureVolumeFunction(std::shared_ptr<PluginAbstractFactory> factory, const PluginConfiguration & configuration, double minVolume);
    virtual ~MeasureVolumeFunction();

    virtual OperationType getAceptedOp();
    virtual bool inWorkingRange(int nargs, va_list args) throw(std::invalid_argument);
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual units::Volume getMinVolume();

    inline virtual bool inWorkingRange(int nargs, va_list args) throw(std::invalid_argument) {
        return true;
    }

protected:
    double minVolume;
    PluginConfiguration configurationObj;
    std::shared_ptr<VolumeSensorProduct> volumeSensorPlugin;
{
public:
    MeasureVolumeFunction();
};

#endif // MEASUREVOLUMEFUNCTION_H
