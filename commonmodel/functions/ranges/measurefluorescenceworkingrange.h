#ifndef MEASUREFLUORESCENCEWORKINGRANGE_H
#define MEASUREFLUORESCENCEWORKINGRANGE_H

#include <utils/units.h>

#include "commonmodel/functions/ranges/comparablerangeinterface.h"

#include "commonmodel/commommodel_global.h"

class MEASUREFLUORESCENCEWORKINGRANGE_EXPORT MeasureFluorescenceWorkingRange : public ComparableRangeInterface
{
public:
    MeasureFluorescenceWorkingRange(const MeasureFluorescenceWorkingRange & mfwr);
    MeasureFluorescenceWorkingRange(units::Length minEmission,
                                    units::Length maxEmission,
                                    units::Length minExcitation,
                                    units::Length maxExcitation);
    virtual ~MeasureFluorescenceWorkingRange();

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const;
    bool inWorkingRange(units::Length emission, units::Length excitation) const;

    inline units::Length getMinEmission() const {
        return minEmission;
    }

    inline void setMinEmission(units::Length minEmission) {
        this->minEmission = minEmission;
    }

    inline units::Length getMaxEmission() const {
        return maxEmission;
    }

    inline void setMaxEmission(units::Length maxEmission) {
        this->maxEmission = maxEmission;
    }

    inline units::Length getMinExcitation() const {
        return minExcitation;
    }

    inline void setMinExcitation(units::Length minExcitation) {
        this->minExcitation = minExcitation;
    }

    inline units::Length getMaxExcitation() const {
        return maxExcitation;
    }

    inline void setMaxExcitation(units::Length maxExcitation) {
        this->maxExcitation = maxExcitation;
    }

protected:
    units::Length minEmission;
    units::Length maxEmission;
    units::Length minExcitation;
    units::Length maxExcitation;
};

#endif // MEASUREFLUORESCENCEWORKINGRANGE_H
