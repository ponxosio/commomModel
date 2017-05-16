#include "shakeworkingrange.h"

ShakeWorkingRange::ShakeWorkingRange(const ShakeWorkingRange & swr) {
    this->minIntensity = swr.minIntensity;
    this->maxIntensity = swr.maxIntensity;
}

ShakeWorkingRange::ShakeWorkingRange(units::Frequency minIntensity, units::Frequency maxIntensity) {
    this->minIntensity = minIntensity;
    this->maxIntensity = maxIntensity;
}

bool ShakeWorkingRange::compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const {
    bool compatible = false;
    const std::shared_ptr<const ShakeWorkingRange> cast = std::dynamic_pointer_cast<const ShakeWorkingRange>(otherRange);
    if (cast) {
        compatible = ((cast->minIntensity >= this->minIntensity) && (cast->maxIntensity <= this->maxIntensity));
    }
    return compatible;
}

bool ShakeWorkingRange::inWorkingRange(units::Frequency intensity) const {
    return ((intensity >= minIntensity) && (intensity <= minIntensity));
}
