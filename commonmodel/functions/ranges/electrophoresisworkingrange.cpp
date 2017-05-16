#include "electrophoresisworkingrange.h"

ElectrophoresisWorkingRange::ElectrophoresisWorkingRange(const ElectrophoresisWorkingRange & otherRange) {
    this->minEField = otherRange.minEField;
    this->maxEField = otherRange.maxEField;
}

ElectrophoresisWorkingRange::ElectrophoresisWorkingRange(units::ElectricField minEField, units::ElectricField maxEField) {
    this->minEField = minEField;
    this->maxEField = maxEField;
}

ElectrophoresisWorkingRange::~ElectrophoresisWorkingRange() {

}

bool ElectrophoresisWorkingRange::compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const {
    bool compatible = false;
    const std::shared_ptr<const ElectrophoresisWorkingRange> cast = std::dynamic_pointer_cast<const ElectrophoresisWorkingRange>(otherRange);
    if (cast) {
        compatible = ((cast->minEField >= this->minEField) && (cast->maxEField <= this->maxEField));
    }
    return compatible;
}

bool ElectrophoresisWorkingRange::inWorkingRange(units::ElectricField value) const {
    return (value >= minEField) && (value <= maxEField);
}
