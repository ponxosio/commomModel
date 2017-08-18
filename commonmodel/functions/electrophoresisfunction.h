#ifndef ELECTROPHORESISFUNCTION_H
#define ELECTROPHORESISFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/functions/function.h"
#include "commonmodel/functions/ranges/electrophoresisworkingrange.h"

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/centrifugatepluginproduct.h"

#include "commonmodel/commommodel_global.h"

class ELECTROPHORESISFUNCTION_EXPORT ElectrophoresisFunction : public Function
{
public:
    ElectrophoresisFunction(std::shared_ptr<PluginAbstractFactory> factory,
                            const PluginConfiguration & configuration,
                            units::Volume minVolume,
                            const ElectrophoresisWorkingRange & workingRange);
    virtual ~ElectrophoresisFunction();

    virtual OperationType getAceptedOp() const ;

    virtual bool inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument);
    virtual const std::shared_ptr<const ComparableRangeInterface> getComparableWorkingRange() const;

    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);
    virtual units::Volume getMinVolume() const;

    virtual void stopOperation();

protected:
    bool running;
    units::Volume minVolume;
    std::shared_ptr<ElectrophoresisWorkingRange> workingRange;

    std::shared_ptr<PluginConfiguration> configurationObj;
    std::shared_ptr<ElectrophoresisPluginProduct> electrophoresisPlugin;
};

#endif // ELECTROPHORESISFUNCTION_H
