#include <math.h>
#include "../include/compare.h"

bool check_equal(const double equal1, const double equal2, const double tolerance) {
    return fabs(equal1 - equal2) < tolerance;
}

bool check_greater(const double greater, const double lower, const double tolerance) {
    return (greater - lower) > tolerance;
}

bool check_lower(const double lower, const double greater, const double tolerance) {
    return (greater - lower) > tolerance;
}
