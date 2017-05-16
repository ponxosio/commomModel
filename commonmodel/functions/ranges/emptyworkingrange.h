#ifndef EMPTYWORKINGRANGE_H
#define EMPTYWORKINGRANGE_H

#include "commonmodel/functions/ranges/comparablerangeinterface.h"

class EmptyWorkingRange : public ComparableRangeInterface
{
public:
    EmptyWorkingRange(){}
    virtual ~EmptyWorkingRange(){}

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const;
};

#endif // EMPTYWORKINGRANGE_H
