#include "heaterworkingrange.h"

HeaterWorkingRange::HeaterWorkingRange(const HeaterWorkingRange & hwr) :
    ComparableRangeInterface(hwr)
{
    this->minTemperature = hwr.minTemperature;
    this->maxTemperature = hwr.maxTemperature;
}

HeaterWorkingRange::HeaterWorkingRange(units::Temperature minTemperature, units::Temperature maxTemperature) :
    ComparableRangeInterface()
{
    this->minTemperature = minTemperature;
    this->maxTemperature = maxTemperature;
}

HeaterWorkingRange::~HeaterWorkingRange() {

}

bool HeaterWorkingRange::compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const {
    bool compatible = false;
    const std::shared_ptr<const HeaterWorkingRange> cast = std::dynamic_pointer_cast<const HeaterWorkingRange>(otherRange);
    if (cast) {
        compatible = this->infinite || otherRange->isInfinite() ||
                    ((cast->minTemperature >= this->minTemperature) && (cast->maxTemperature <= this->maxTemperature));
    }
    return compatible;
}

bool HeaterWorkingRange::inWorkingRange(units::Temperature value) const {
    return (value >= minTemperature) && (value <= maxTemperature);
}
