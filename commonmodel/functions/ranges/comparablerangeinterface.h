#ifndef COMPARABLERANGEINTERFACE_H
#define COMPARABLERANGEINTERFACE_H

#include <memory>

class ComparableRangeInterface
{
public:
    virtual ~ComparableRangeInterface(){}

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const = 0;
};

#endif // COMPARABLERANGEINTERFACE_H
