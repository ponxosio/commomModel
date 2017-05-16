#include "emptyworkingrange.h"

bool EmptyWorkingRange::compatible(const std::shared_ptr<const ComparableRangeInterface> otherRange) const {
    bool compatible = false;
    const std::shared_ptr<const EmptyWorkingRange> cast = std::dynamic_pointer_cast<const EmptyWorkingRange>(otherRange);
    if (cast) {
        compatible = true;
    }
    return compatible;
}
