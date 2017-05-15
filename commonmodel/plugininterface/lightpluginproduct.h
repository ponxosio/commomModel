#ifndef LIGHTPLUGINPRODUCT_H
#define LIGHTPLUGINPRODUCT_H

#include <utils/units.h>

class LightPluginProduct
{
public:
    virtual ~LightPluginProduct(){}

    virtual void applyLight(units::LuminousIntensity intensity, units::Length wavelenght) = 0;
    virtual void turnOffLight() = 0;
    virtual bool inWorkingRange(units::LuminousIntensity intensity2check, units::Length wavelength2check) = 0;
};

#endif // LIGHTPLUGINPRODUCT_H
