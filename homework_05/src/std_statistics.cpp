#include <math.h>
#include "std_statistics.hpp"

namespace stat {
    size_t capacity = 10;
    double sum = 0;
    int count = 0;

    double *allocateNewArray(size_t cap) {
        return (double *)malloc(sizeof(double) * cap);
    }

    void extendArrayOfElements(double *elements, size_t newCapacity) {
        double *new_elem = allocateNewArray(newCapacity);
        for (int i = 0; i < count - 2 ; ++i) {
            new_elem[i] = elements[i];
        }
        delete elements;
        elements = new_elem;
    }

    Std::Std() :
        elements{allocateNewArray(capacity)}
        {};

    Std::~Std() {
        delete elements;
    }

    void Std::update(double next) {
        sum += next;
        count++;
        if (count > 10) {
            capacity += 10;
            extendArrayOfElements(Std::elements, capacity);
        }
        this->elements[count - 1] = next;
    }

    double Std::eval() const {
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

    const char *Std::name() const {
        return "std";
    }
}
