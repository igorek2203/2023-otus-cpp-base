#pragma once

#include "statistics.hpp"

namespace stat {
    class Mean : public IStatistics {
        public:
            explicit Mean();
            ~Mean() = default;

            void update(double next) override;
            double eval() const override;
            const char *name() const override;

        private:
            double sum;
            int count;
    };
}
