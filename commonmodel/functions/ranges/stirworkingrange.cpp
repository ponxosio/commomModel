#include "stirworkingrange.h"

StirWorkingRange::StirWorkingRange(const StirWorkingRange & swr) :
    ComparableRangeInterface(swr)
{
    this->minIntensity = swr.minIntensity;
    this->maxIntensity = swr.maxIntensity;
}

StirWorkingRange::StirWorkingRange(units::Frequency minIntensity, units::Frequency maxIntensity) :
    ComparableRangeInterface()
{
    this->minIntensity = minIntensity;
    this->maxIntensity = maxIntensity;
}

StirWorkingRange::~StirWorkingRange() {

}

bool StirWorkingRange::compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const {
    bool compatible = false;
    const std::shared_ptr<const StirWorkingRange> cast = std::dynamic_pointer_cast<const StirWorkingRange>(otherRange);
    if (cast) {
        compatible = this->infinite || otherRange->isInfinite() ||
                    ((cast->minIntensity >= this->minIntensity) && (cast->maxIntensity <= this->maxIntensity));
    }
    return compatible;
}

bool StirWorkingRange::inWorkingRange(units::Frequency intensity) const {
    return ((intensity >= minIntensity) && (intensity <= minIntensity));
}
