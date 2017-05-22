#include "centrifugationworkingrange.h"

CentrifugationWorkingRange::CentrifugationWorkingRange(const CentrifugationWorkingRange & otherRange) :
    ComparableRangeInterface(otherRange)
{
    this->maxIntensity = otherRange.maxIntensity;
    this->minIntensity = otherRange.minIntensity;
}

CentrifugationWorkingRange::CentrifugationWorkingRange(units::Frequency minIntensity, units::Frequency maxIntensity) :
    ComparableRangeInterface()
{
    this->minIntensity = minIntensity;
    this->maxIntensity = maxIntensity;
}

CentrifugationWorkingRange::~CentrifugationWorkingRange() {

}

bool CentrifugationWorkingRange::compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const {
    bool compatible = false;
    const std::shared_ptr<const CentrifugationWorkingRange> cast = std::dynamic_pointer_cast<const CentrifugationWorkingRange>(otherRange);
    if (cast) {
        compatible = this->infinite || otherRange->isInfinite() ||
                     ((cast->minIntensity >= this->minIntensity) && (cast->maxIntensity <= this->maxIntensity));
    }
    return compatible;
}

bool CentrifugationWorkingRange::inWorkingRange(units::Frequency value) const {
    return ((value >= minIntensity) && (value <= maxIntensity));
}
