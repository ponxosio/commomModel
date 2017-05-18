#ifndef COMPARABLERANGEINTERFACE_H
#define COMPARABLERANGEINTERFACE_H

#include <memory>
#include <string>

class ComparableRangeInterface
{
public:
    virtual ~ComparableRangeInterface(){}

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const = 0;
    virtual std::string toString() const = 0;
};

#endif // COMPARABLERANGEINTERFACE_H
