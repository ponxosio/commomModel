#ifndef PUMPWORKINGRANGE_H
#define PUMPWORKINGRANGE_H

#include <utils/units.h>

#include "commonmodel/functions/ranges/comparablerangeinterface.h"

#include "commonmodel/commommodel_global.h"

class PUMPWORKINGRANGE_EXPORT PumpWorkingRange : public ComparableRangeInterface
{
public:
    PumpWorkingRange(const PumpWorkingRange & pwr);
    PumpWorkingRange(units::Volumetric_Flow minRate, units::Volumetric_Flow maxRate);
    virtual ~PumpWorkingRange();

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const;
    bool inWorkingRange(units::Volumetric_Flow rate) const;

    inline units::Volumetric_Flow getMinRate() const {
        return minRate;
    }

    inline void setMinRate(units::Volumetric_Flow minRate) {
        this->minRate = minRate;
    }

    inline units::Volumetric_Flow getMaxRate() const {
        return maxRate;
    }

    inline void setMaxRate(units::Volumetric_Flow maxRate) {
        this->maxRate = maxRate;
    }

protected:
    units::Volumetric_Flow minRate;
    units::Volumetric_Flow maxRate;
};

#endif // PUMPWORKINGRANGE_H
