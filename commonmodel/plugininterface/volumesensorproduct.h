#ifndef VOLUMESENSORPRODUCT_H
#define VOLUMESENSORPRODUCT_H

#include <utils/units.h>

class VolumeSensorProduct
{
public:
    VolumeSensorProduct(){}
    virtual ~VolumeSensorProduct(){}

    virtual void startMeasureVolume(units::Frequency measurementFrequency) = 0;
    virtual units::Volume getVolumeMeasurement() = 0;
};

#endif // VOLUMESENSORPRODUCT_H
