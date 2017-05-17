#ifndef HEATERWORKINGRANGE_H
#define HEATERWORKINGRANGE_H

#include <utils/units.h>

#include "commonmodel/functions/ranges/comparablerangeinterface.h"

#include "commonmodel/commommodel_global.h"

class HEATERWORKINGRANGE_EXPORT HeaterWorkingRange : public ComparableRangeInterface
{
public:
    HeaterWorkingRange(const HeaterWorkingRange & hwr);
    HeaterWorkingRange(units::Temperature minTemperature, units::Temperature maxTemperature);
    virtual ~HeaterWorkingRange();

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const;
    bool inWorkingRange(units::Temperature value) const;

    inline units::Temperature getMinTemperature() const {
        return minTemperature;
    }

    inline void setMinTemperature(units::Temperature minTemperature) {
        this->minTemperature = minTemperature;
    }

    inline units::Temperature getMaxTemperature() const {
        return maxTemperature;
    }

    inline void setMaxTemperature(units::Temperature maxTemperature) {
        this->maxTemperature = maxTemperature;
    }

protected:
    units::Temperature minTemperature;
    units::Temperature maxTemperature;
};

#endif // HEATERWORKINGRANGE_H
