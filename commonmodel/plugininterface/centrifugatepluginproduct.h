#ifndef CENTRIFUGATEPLUGINPRODUCT_H
#define CENTRIFUGATEPLUGINPRODUCT_H

#include <utils/units.h>

class CentrifugatePluginProduct
{
public:
    virtual ~CentrifugatePluginProduct(){}

    virtual void startCentrifugate(units::Frequency intensity) = 0;
    virtual void turnOff() = 0;
};

#endif // CENTRIFUGATEPLUGINPRODUCT_H
