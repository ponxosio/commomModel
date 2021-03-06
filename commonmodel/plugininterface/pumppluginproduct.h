#ifndef PUMPPLUGINPRODUCT_H
#define PUMPPLUGINPRODUCT_H

#include <utils/units.h>

class PumpPluginProduct {
public:
    virtual ~PumpPluginProduct(){}

    virtual void setPumpState(int dir, units::Volumetric_Flow rate) = 0;
    virtual void stopPump() = 0;
};

#endif // PUMPPLUGINPRODUCT_H
