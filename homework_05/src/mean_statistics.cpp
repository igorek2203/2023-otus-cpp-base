#include <limits>
#include "statistics.hpp"

namespace stat {
    class Mean : public IStatistics {
    public:
        explicit Mean() : 
            sum{0},
            count{0}
            {}

        void update(double next) override {
            sum += next;
            count++;
        }

        double eval() const override {
            return count == 0 ? 0 : sum/count;
        }

        const char * name() const override {
            return "mean";
        }

    private:
        double sum;
        int count;
    };
}
