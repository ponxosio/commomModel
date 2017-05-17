#ifndef LIGTHWORKINGRANGE_H
#define LIGTHWORKINGRANGE_H

#include <utils/units.h>

#include "commonmodel/functions/ranges/comparablerangeinterface.h"

#include "commonmodel/commommodel_global.h"

class LIGTHWORKINGRANGE_EXPORT LigthWorkingRange : public ComparableRangeInterface
{
public:
    LigthWorkingRange(const LigthWorkingRange & lwr);
    LigthWorkingRange(units::Length minWaveLength,
                      units::Length maxWaveLength,
                      units::LuminousIntensity minIntensity,
                      units::LuminousIntensity maxIntensity);
    virtual ~LigthWorkingRange();

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const;
    bool inWorkingRange(units::Length wavelength, units::LuminousIntensity intensity) const;

    inline units::Length getMinWaveLength() const {
        return minWaveLength;
    }

    inline void setMinWaveLength(units::Length minWaveLength) {
        this->minWaveLength = minWaveLength;
    }

    inline units::Length getMaxWaveLength() const {
        return maxWaveLength;
    }

    inline void setMaxWaveLength(units::Length maxWaveLength) {
        this->maxWaveLength = maxWaveLength;
    }

    inline units::LuminousIntensity getMinIntensity() const {
        return minIntensity;
    }

    inline void setMinIntensity(units::LuminousIntensity minIntensity) {
        this->minIntensity = minIntensity;
    }

    inline units::LuminousIntensity getMaxIntensity() const {
        return maxIntensity;
    }

    inline void setMaxIntensity(units::LuminousIntensity maxIntensity) {
        this->maxIntensity = maxIntensity;
    }

protected:
    units::Length minWaveLength;
    units::Length maxWaveLength;
    units::LuminousIntensity minIntensity;
    units::LuminousIntensity maxIntensity;
};

#endif // LIGTHWORKINGRANGE_H
