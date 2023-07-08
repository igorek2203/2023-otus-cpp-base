#pragma once

#include "statistics.hpp"

namespace stat {
    class Max : public IStatistics {
        public:
            explicit Max();
            ~Max() = default;

            void update(double next);
            double eval() const;
            const char *name() const;
            
        private:
            double m_max;
    };
} //stat
