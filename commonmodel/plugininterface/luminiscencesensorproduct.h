#ifndef LUMINISCENCESENSORPRODUCT_H
#define LUMINISCENCESENSORPRODUCT_H

#include <utils/units.h>

class LuminiscenceSensorProduct
{
public:
    virtual ~LuminiscenceSensorProduct(){}

    virtual void startMeasureLuminiscence(units::Frequency measurementFrequency) = 0;
    virtual units::LuminousIntensity getLuminiscenceMeasurement() = 0;
};

#endif // LUMINISCENCESENSORPRODUCT_H
