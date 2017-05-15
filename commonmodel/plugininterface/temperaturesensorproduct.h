#ifndef TEMPERATURESENSORPRODUCT_H
#define TEMPERATURESENSORPRODUCT_H

#include <utils/units.h>

class TemperatureSensorProduct
{
public:
    TemperatureSensorProduct(){}
    virtual ~TemperatureSensorProduct(){}

    virtual void startMeasureTemperature(units::Frequency measurementFrequency) = 0;
    virtual units::Temperature getTemperatureMeasurement() = 0;
};

#endif // TEMPERATURESENSORPRODUCT_H
