#ifndef SHAKEPLUGINPRODUCT_H
#define SHAKEPLUGINPRODUCT_H

#include <utils/units.h>

class ShakePluginProduct
{
public:
    virtual ~ShakePluginProduct(){}

    virtual void startShake(units::Frequency intensity) = 0;
    virtual void stopShake() = 0;
    virtual bool inWorkingRange(units::Frequency value2check) = 0;

#endif // SHAKEPLUGINPRODUCT_H
