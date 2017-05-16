#ifndef STIRERPLUGINPRODUCT_H
#define STIRERPLUGINPRODUCT_H

#include <utils/units.h>

class StirerPluginProduct
{
public:
    StirerPluginProduct(){}
    virtual ~StirerPluginProduct(){}

    virtual void stir(units::Frequency intensity) = 0;
    virtual void turnOff() = 0;
};

#endif // STIRERPLUGINPRODUCT_H
