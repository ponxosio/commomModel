#ifndef ELECTROPHORESISWORKINGRANGE_H
#define ELECTROPHORESISWORKINGRANGE_H

#include <utils/units.h>

#include "commonmodel/functions/ranges/comparablerangeinterface.h"

#include "commonmodel/commommodel_global.h"

class ELECTROPHORESISWORKINGRANGE_EXPORT ElectrophoresisWorkingRange : public ComparableRangeInterface
{
public:
    ElectrophoresisWorkingRange(const ElectrophoresisWorkingRange & otherRange);
    ElectrophoresisWorkingRange(units::ElectricField minEField, units::ElectricField maxEField);
    virtual ~ElectrophoresisWorkingRange();

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const;
    bool inWorkingRange(units::ElectricField value) const;

    inline units::ElectricField getMinEField() const {
        return minEField;
    }

    inline void setMinEField(units::ElectricField minEField) {
        this->minEField = minEField;
    }

    inline units::ElectricField getMaxEField() const {
        return maxEField;
    }

    inline void setMaxEField(units::ElectricField maxEField) {
        this->maxEField = maxEField;
    }

protected:
    units::ElectricField minEField;
    units::ElectricField maxEField;
};

#endif // ELECTROPHORESISWORKINGRANGE_H
