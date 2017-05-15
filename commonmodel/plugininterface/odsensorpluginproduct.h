#ifndef ODSENSORPLUGINPRODUCT_H
#define ODSENSORPLUGINPRODUCT_H

#include <utils/units.h>

class OdSensorPluginProduct
{
public:
    virtual ~OdSensorPluginProduct(){}

    virtual void startMeasureOd(units::Frequency measurementFrequency, units::Length waveLength) = 0;
    virtual double getOdMeasurement() = 0;
    virtual bool inWorkingRange(units::Length wavelength2check) = 0;
};

#endif // ODSENSORPLUGINPRODUCT_H
