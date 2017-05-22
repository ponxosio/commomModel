#include "ligthworkingrange.h"

LigthWorkingRange::LigthWorkingRange(const LigthWorkingRange & lwr) :
    ComparableRangeInterface(lwr)
{
    this->minIntensity = lwr.minIntensity;
    this->maxIntensity = lwr.maxIntensity;
    this->minWaveLength = lwr.maxWaveLength;
    this->minWaveLength = lwr.minWaveLength;
}

LigthWorkingRange::LigthWorkingRange(
        units::Length minWaveLength,
        units::Length maxWaveLength,
        units::LuminousIntensity minIntensity,
        units::LuminousIntensity maxIntensity) :
    ComparableRangeInterface()
{
    this->minIntensity = minIntensity;
    this->maxIntensity = maxIntensity;
    this->minWaveLength = minWaveLength;
    this->maxWaveLength = maxWaveLength;
}

LigthWorkingRange::~LigthWorkingRange() {

}

bool LigthWorkingRange::compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const {
    bool compatible = false;
    const std::shared_ptr<const LigthWorkingRange> cast = std::dynamic_pointer_cast<const LigthWorkingRange>(otherRange);
    if (cast) {
        compatible = this->infinite || otherRange->isInfinite() ||
                     (((cast->minWaveLength >= this->minWaveLength) && (cast->maxWaveLength <= this->maxWaveLength)) &&
                     (cast->minIntensity >= this->minIntensity) && (cast->maxIntensity <= this->maxIntensity));
    }
    return compatible;
}

bool LigthWorkingRange::inWorkingRange(units::Length wavelength, units::LuminousIntensity intensity) const {
    return (((wavelength >= minWaveLength) && (wavelength <= maxWaveLength)) &&
            ((intensity >= minIntensity) && (intensity <= maxIntensity)));
}
