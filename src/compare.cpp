#include <math.h>
#include "../include/compare.h"

bool equal(const double value1, const double value2, const double tolerance) {
    return fabs(value1 - value2) < tolerance;
}

bool over(const double value1, const double value2, const double tolerance) {
    return (value1 - value2) > tolerance;
}

bool below(const double value1, const double value2, const double tolerance) {
    return (value2 - value1) > tolerance;
}
