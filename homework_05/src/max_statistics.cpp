#include <limits>
#include "max_statistics.hpp"

namespace stat {
    Max::Max() :
        m_max{std::numeric_limits<double>::lowest()}
        {}

    void Max::update(double next) {
        if (next > Max::m_max) {
            Max::m_max = next;
        }
    }

    double Max::eval() const {
        return Max::m_max;
    }

    const char *Max::name() const {
        return "max";
    }
}
