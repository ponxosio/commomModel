#ifndef EMPTYWORKINGRANGE_H
#define EMPTYWORKINGRANGE_H

#include "commonmodel/functions/ranges/comparablerangeinterface.h"

#include "commonmodel/commommodel_global.h"

class EMPTYWORKINGRANGE_EXPORT EmptyWorkingRange : public ComparableRangeInterface
{
public:
    EmptyWorkingRange() : ComparableRangeInterface() {}
    virtual ~EmptyWorkingRange(){}

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const;

    inline virtual std::string toString() const {
        return "[]";
    }
};

#endif // EMPTYWORKINGRANGE_H
