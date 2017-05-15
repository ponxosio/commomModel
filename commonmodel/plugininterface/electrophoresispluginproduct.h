#ifndef ELECTROPHORESISPLUGINPRODUCT_H
#define ELECTROPHORESISPLUGINPRODUCT_H

#include <memory>

#include <utils/units.h>
#include <utils/electrophoresisresult.h>

class ElectrophoresisPluginProduct
{
public:
    virtual ~ElectrophoresisPluginProduct(){}

    virtual void startElectrophoresis(units::ElectricField fieldStrenght) = 0;
    virtual std::shared_ptr<ElectrophoresisResult> stopElectrophpresis() = 0;    
};

#endif // ELECTROPHORESISPLUGINPRODUCT_H
