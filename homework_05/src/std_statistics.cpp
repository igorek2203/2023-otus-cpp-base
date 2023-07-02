#include <limits>
#include <math.h>
#include "statistics.hpp"

namespace stat {
    class Std : public IStatistics {
    public:
        explicit Std() : 
            sum{0},
            count{0},
            capacity{10}
            {
                elements = allocateNewArray(capacity);
            }

        ~Std() {
            delete elements;
        }

        void update(double next) override {
            sum += next;
            count++;
            if (count > 10) {
                extendArrayOfElements(next);
            } else {
                this->elements[count - 1] = next;
            }
        }

        double eval() const override {
            if (count == 0) {
                return 0;
            }
            double avg = sum / count;
            double diff = 0;
            double sumDiff = 0;
            for (int i = 0; i < count; ++i) {
                diff = elements[i] - avg;
                sumDiff += (diff * diff);
            }
            return std::sqrt(sumDiff / count);
        }

        const char * name() const override {
            return "std";
        }

    private:
        double sum;
        int count;
        double *elements;
        size_t capacity;

        double *allocateNewArray(size_t cap) {
            return (double *)malloc(sizeof(double) * cap);
        }

        void extendArrayOfElements(double next) {
            capacity += 10;
            double *new_elem = allocateNewArray(capacity);
            for (int i = 0; i < count - 2 ; ++i) {
                new_elem[i] = this->elements[i];
            }
            new_elem[count - 1] = next;
            delete this->elements;
            this->elements = new_elem;
        }
    };
}
