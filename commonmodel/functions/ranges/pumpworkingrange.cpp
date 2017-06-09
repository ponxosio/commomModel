#include "pumpworkingrange.h"

PumpWorkingRange::PumpWorkingRange(const PumpWorkingRange & pwr) :
    ComparableRangeInterface(pwr)
{
    this->minRate = pwr.minRate;
    this->maxRate = pwr.maxRate;
}

PumpWorkingRange::PumpWorkingRange(units::Volumetric_Flow minRate, units::Volumetric_Flow maxRate) :
    ComparableRangeInterface()
{
    this->minRate = minRate;
    this->maxRate = maxRate;
}

PumpWorkingRange::~PumpWorkingRange() {

}

bool PumpWorkingRange::compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const {
    bool compatible = false;
    const std::shared_ptr<const PumpWorkingRange> cast = std::dynamic_pointer_cast<const PumpWorkingRange>(otherRange);
    if (cast) {
        compatible = this->infinite || otherRange->isInfinite() ||
                    ((cast->minRate >= this->minRate) && (cast->maxRate <= this->maxRate));
    }
    return compatible;
}

bool PumpWorkingRange::inWorkingRange(units::Volumetric_Flow rate) const {
    return ((rate >= minRate) && (rate <= maxRate));
}
