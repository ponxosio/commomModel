#ifndef MEASUREODWORKINGRANGE_H
#define MEASUREODWORKINGRANGE_H

#include <utils/units.h>

#include "commonmodel/functions/ranges/comparablerangeinterface.h"

#include "commonmodel/commommodel_global.h"

class MEASUREODWORKINGRANGE_EXPORT MeasureOdWorkingRange : public ComparableRangeInterface
{
public:
    MeasureOdWorkingRange(const MeasureOdWorkingRange & mowr);
    MeasureOdWorkingRange(units::Length minWavelength, units::Length maxWavelength);
    virtual ~MeasureOdWorkingRange();

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const;
    bool inWorkingRange(units::Length wavelength) const;

    inline virtual std::string toString() const {
        std::stringstream stream;
        stream << "[" << minWavelength.to(units::nm) << " nm, " << maxWavelength.to(units::nm) << "nm]";
        return stream.str();
    }

    inline units::Length getMinWaveLength() const {
        return minWavelength;
    }

    inline void setMinWaveLength(units::Length minWaveLength) {
        this->minWavelength = minWaveLength;
    }

    inline units::Length getMaxWaveLength() const {
        return maxWavelength;
    }

    inline void setMaxWaveLength(units::Length maxWaveLength) {
        this->maxWavelength = maxWaveLength;
    }

protected:
    units::Length minWavelength;
    units::Length maxWavelength;
};

#endif // MEASUREODWORKINGRANGE_H
