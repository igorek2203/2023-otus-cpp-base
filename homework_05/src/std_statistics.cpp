#include <math.h>
#include <iostream>
#include "std_statistics.hpp"

namespace stat {
    size_t capacity = 5;

    double *newArray(size_t cap) {
        return new double[cap]{};
    }

    void extendArrayOfElements(double *&elements, int count, size_t newCapacity) {
        double *new_elem  = newArray(newCapacity);
        for (int i = 0; i < count; ++i) {
           new_elem[i] = elements[i];
        }
        delete[] elements;
        elements = new_elem;
        new_elem = NULL;
    }

    Std::Std() :
        count{0},
        sum{0}
        {
            elements = newArray(capacity);
        };

    Std::~Std() {
        delete[] elements;
    }

    void Std::update(double next) {
        sum += next;
        elements[count] = next;
        count++;
        if ((size_t) count >= capacity) {
            capacity += 5;
            extendArrayOfElements(elements, count, capacity);
        }
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
