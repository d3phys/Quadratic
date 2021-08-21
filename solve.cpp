#include <math.h>
#include "quadratic.h"

int solve(square_params coeffs, square_solutions *solutions) {
    double discriminant = coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;

    if (discriminant == 0) {
        solutions->x1 = (-coeffs.b) / (2.0 * coeffs.a);
        return 1;
    } else if (discriminant > 0) {
        double sqrt_discr = sqrt(discriminant);
        solutions->x1 = (-coeffs.b + sqrt_discr) / (2.0 * coeffs.a);
        solutions->x2 = (-coeffs.b - sqrt_discr) / (2.0 * coeffs.a);
        return 2;
    }
    return 0;
}
