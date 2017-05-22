#ifndef COMPARABLERANGEINTERFACE_H
#define COMPARABLERANGEINTERFACE_H

#include <memory>
#include <string>

class ComparableRangeInterface
{
public:
    ComparableRangeInterface() {
        infinite = false;
    }
    ComparableRangeInterface(const ComparableRangeInterface & cmp) {
        this->infinite = cmp.infinite;
    }

    virtual ~ComparableRangeInterface(){}

    virtual bool compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const = 0;
    virtual std::string toString() const = 0;

    inline bool isInfinite() const {
        return infinite;
    }

    inline void setInfinite(bool isInfinite) {
        infinite = isInfinite;
    }

protected:
    bool infinite;
};

#endif // COMPARABLERANGEINTERFACE_H
