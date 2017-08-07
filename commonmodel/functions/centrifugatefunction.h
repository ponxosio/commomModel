#ifndef CENTRIFUGATEFUNCTION_H
#define CENTRIFUGATEFUNCTION_H

#include <memory>
#include <cstdarg>

#include "commonmodel/functions/function.h"
#include "commonmodel/functions/ranges/centrifugationworkingrange.h"

#include "commonmodel/plugininterface/pluginabstractfactory.h"
#include "commonmodel/plugininterface/pluginconfiguration.h"
#include "commonmodel/plugininterface/centrifugatepluginproduct.h"

#include "commonmodel/commommodel_global.h"

class CENTRIFUGATEFUNCTION_EXPORT CentrifugateFunction : public Function
{
public:
    CentrifugateFunction(std::shared_ptr<PluginAbstractFactory> factory,
                         const PluginConfiguration & configuration,
                         units::Volume minVolume,
                         const CentrifugationWorkingRange & workingRange);
    virtual ~CentrifugateFunction();

    virtual OperationType getAceptedOp() const;
    virtual std::shared_ptr<MultiUnitsWrapper> doOperation(int nargs, va_list args) throw (std::invalid_argument);

    virtual bool inWorkingRange(int nargs, va_list args) const throw(std::invalid_argument);
    virtual const std::shared_ptr<const ComparableRangeInterface> getComparableWorkingRange() const;
    virtual units::Volume getMinVolume() const;

    virtual void stopOperation();

protected:
    bool running;
    units::Volume minVolume;
    std::shared_ptr<CentrifugationWorkingRange> workingRange;

    std::shared_ptr<PluginConfiguration> configurationObj;
    std::shared_ptr<CentrifugatePluginProduct> centrifugatePlugin;
};

#endif // CENTRIFUGATEFUNCTION_H
