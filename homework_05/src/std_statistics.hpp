#pragma once

#include "statistics.hpp"

namespace stat {
    class Std : public IStatistics {
    public:
        explicit Std();
        Std(Std &other) = delete;
        Std &operator=(const Std &other) = delete;
        virtual ~Std();

        void update(double next) override;
        double eval() const override;
        const char *name() const override;

    private:
        double *elements;
    };
}
