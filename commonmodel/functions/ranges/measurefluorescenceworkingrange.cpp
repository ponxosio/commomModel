#include "measurefluorescenceworkingrange.h"

MeasureFluorescenceWorkingRange::MeasureFluorescenceWorkingRange(const MeasureFluorescenceWorkingRange & mfwr) :
    ComparableRangeInterface(mfwr)
{
    this->minEmission = mfwr.minEmission;
    this->maxEmission = mfwr.maxEmission;
    this->minExcitation = mfwr.minExcitation;
    this->maxExcitation = mfwr.maxExcitation;
}

MeasureFluorescenceWorkingRange::MeasureFluorescenceWorkingRange(
        units::Length minEmission,
        units::Length maxEmission,
        units::Length minExcitation,
        units::Length maxExcitation) :
    ComparableRangeInterface()
{
    this->minEmission = minEmission;
    this->maxEmission = maxEmission;
    this->minExcitation = minExcitation;
    this->maxExcitation = maxExcitation;
}

MeasureFluorescenceWorkingRange::~MeasureFluorescenceWorkingRange() {

}

bool MeasureFluorescenceWorkingRange::compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const {
    bool compatible = false;
    const std::shared_ptr<const MeasureFluorescenceWorkingRange> cast =
                    std::dynamic_pointer_cast<const MeasureFluorescenceWorkingRange>(otherRange);
    if (cast) {
        compatible = this->infinite || otherRange->isInfinite() ||
                     (((cast->minEmission >= this->minEmission) && (cast->maxEmission <= this->maxEmission)) &&
                     (cast->minExcitation >= this->minExcitation) && (cast->maxExcitation <= this->maxExcitation));
    }
    return compatible;
}

bool MeasureFluorescenceWorkingRange::inWorkingRange(units::Length emission, units::Length excitation) const {
    return (((emission >= minEmission) && (emission <= maxEmission)) &&
            ((excitation >= maxExcitation) && (excitation <= minExcitation)));
}
