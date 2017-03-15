#ifndef HEATERPLUGINPRODUCT_H
#define HEATERPLUGINPRODUCT_H

#include <utils/units.h>

class HeaterPluginProduct
{
public:
    HeaterPluginProduct(){}
    virtual ~HeaterPluginProduct(){}

    virtual void changeTemperature(units::Temperature value) = 0;
};

#endif // HEATERPLUGINPRODUCT_H
