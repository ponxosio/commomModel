#ifndef FLUORESCENCESENSORPRODUCT_H
#define FLUORESCENCESENSORPRODUCT_H

#include <utils/units.h>

class FluorescenceSensorProduct
{
public:
    virtual ~FluorescenceSensorProduct(){}

    virtual void startMeasureFluorescence(units::Frequency measurementFrequency, units::Length excitation, units::Length emission) = 0;
    virtual units::LuminousIntensity getFluorescenceMeasurement() = 0;
    virtual bool inWorkingRange(units::Length excitation2check, units::Length emission2check) = 0;
};

#endif // FLUORESCENCESENSORPRODUCT_H
