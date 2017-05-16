#ifndef HEATERPLUGINPRODUCT_H
#define HEATERPLUGINPRODUCT_H

#include <utils/units.h>

class HeaterPluginProduct
{
public:
    virtual ~HeaterPluginProduct(){}

    virtual void changeTemperature(units::Temperature value) = 0;
    virtual void turnOff() = 0;
};

#endif // HEATERPLUGINPRODUCT_H
