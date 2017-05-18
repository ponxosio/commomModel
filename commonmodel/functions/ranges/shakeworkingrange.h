#ifndef SHAKEWORKINGRANGE_H
#define SHAKEWORKINGRANGE_H

#include <utils/units.h>

#include "commonmodel/functions/ranges/comparablerangeinterface.h"

#include "commonmodel/commommodel_global.h"

class SHAKEWORKINGRANGE_EXPORT ShakeWorkingRange : public ComparableRangeInterface
{
public:
    ShakeWorkingRange(const ShakeWorkingRange & swr);
    ShakeWorkingRange(units::Frequency minIntensity, units::Frequency maxIntensity);

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const;
    bool inWorkingRange(units::Frequency intensity) const;

    inline virtual std::string toString() const {
        std::stringstream stream;
        stream << "[" << minIntensity.to(units::Hz) << " Hz, " << maxIntensity.to(units::Hz) << "Hz]";
        return stream.str();
    }

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

#endif // SHAKEWORKINGRANGE_H
