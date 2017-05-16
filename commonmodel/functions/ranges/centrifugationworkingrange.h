#ifndef CENTRIFUGATIONWORKINGRANGE_H
#define CENTRIFUGATIONWORKINGRANGE_H

#include <utils/units.h>

#include "commonmodel/functions/ranges/comparablerangeinterface.h"

class CentrifugationWorkingRange : public ComparableRangeInterface
{
public:
    CentrifugationWorkingRange(const CentrifugationWorkingRange & otherRange);
    CentrifugationWorkingRange(units::Frequency minIntensity, units::Frequency maxIntensity);
    virtual ~CentrifugationWorkingRange();

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const;
    bool inWorkingRange(units::Frequency value) const;

    inline units::Frequency getMinIntensity() const {
        return minIntensity;
    }

    inline void setMinIntensity(units::Frequency minIntensity) {
        this->minIntensity = minIntensity;
    }

    inline units::Frequency getMaxIntensity() const {
        return maxIntensity;
    }

    inline void setMaxIntensity(units::Frequency maxIntensity) {
        this->maxIntensity = maxIntensity;
    }

protected:
    units::Frequency minIntensity;
    units::Frequency maxIntensity;
};

#endif // CENTRIFUGATIONWORKINGRANGE_H
