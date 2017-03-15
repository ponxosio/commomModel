#ifndef LIGHTPLUGINPRODUCT_H
#define LIGHTPLUGINPRODUCT_H

#include <utils/units.h>

class LightPluginProduct
{
public:
    LightPluginProduct(){}
    virtual ~LightPluginProduct(){}

    virtual void applyLight(units::LuminousIntensity intensity, units::Length wavelenght) = 0;
};

#endif // LIGHTPLUGINPRODUCT_H
