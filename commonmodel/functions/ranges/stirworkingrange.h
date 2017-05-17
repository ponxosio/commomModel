#ifndef STIRWORKINGRANGE_H
#define STIRWORKINGRANGE_H

#include <utils/units.h>

#include "commonmodel/functions/ranges/comparablerangeinterface.h"

#include "commonmodel/commommodel_global.h"

class STIRWORKINGRANGE_EXPORT StirWorkingRange : public ComparableRangeInterface
{
public:
    StirWorkingRange(const StirWorkingRange & swr);
    StirWorkingRange(units::Frequency minIntensity, units::Frequency maxIntensity);
    virtual ~StirWorkingRange();

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const;
    bool inWorkingRange(units::Frequency intensity) const;

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

#endif // STIRWORKINGRANGE_H
