#include <math.h>

// Tricky solution
// inline int compare_tolerant(double v1, double v2, double tolerance) {
//     return (int)((v1-v2)/tolerance);
// }

bool equal(double value1, double value2, double tolerance) {
    return fabs(value1 - value2) < tolerance;
}

bool over(double value1, double value2, double tolerance) {
    return (value1 - value2) > tolerance;
}

bool below(double value1, double value2, double tolerance) {
    return (value2 - value1) > tolerance;
}
