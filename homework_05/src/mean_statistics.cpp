#include <limits>
#include "mean_statistics.hpp"

namespace stat {
    Mean::Mean() : 
        sum{0},
        count{0}
        {}

    void Mean::update(double next) {
        Mean::sum += next;
        Mean::count++;
    }

    double Mean::eval() const {
        return Mean::count == 0 ? 0 : Mean::sum / Mean::count;
    }

    const char *Mean::name() const {
        return "mean";
    }
}
