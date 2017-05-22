#include "measureodworkingrange.h"

MeasureOdWorkingRange::MeasureOdWorkingRange(const MeasureOdWorkingRange & mowr) :
    ComparableRangeInterface(mowr)
{
    this->minWavelength = mowr.minWavelength;
    this->maxWavelength = mowr.maxWavelength;
}

MeasureOdWorkingRange::MeasureOdWorkingRange(units::Length minWavelength, units::Length maxWavelength) :
    ComparableRangeInterface()
{
    this->maxWavelength = maxWavelength;
    this->minWavelength = minWavelength;
}

MeasureOdWorkingRange::~MeasureOdWorkingRange() {

}

bool MeasureOdWorkingRange::compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const {
    bool compatible = false;
    const std::shared_ptr<const MeasureOdWorkingRange> cast = std::dynamic_pointer_cast<const MeasureOdWorkingRange>(otherRange);
    if (cast) {
        compatible = this->infinite || otherRange->isInfinite() ||
                     ((cast->minWavelength >= this->minWavelength) && (cast->maxWavelength <= this->maxWavelength));
    }
    return compatible;
}

bool MeasureOdWorkingRange::inWorkingRange(units::Length wavelength) const {
    return ((wavelength >= minWavelength) && (wavelength <= maxWavelength));
}
