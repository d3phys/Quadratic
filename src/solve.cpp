#include <math.h>
#include <assert.h>
#include "../include/solve.h"
#include "../include/compare.h"

double calc_discr(const square_params coeffs) {
    return coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
}

int solve_linear(const double b, const double c, double *solution) {
    assert(solution);

    if (equal(b, 0)) {
        if (equal(c, 0))
            return -1;
        else 
            return 0;
    } else {
        *solution = (-c) / b;
        return 1;
    }
}

int solve_quadratic(const square_params coeffs, square_solutions *solutions) {
    assert(solutions);

    double discriminant = calc_discr(coeffs);

    if (equal(coeffs.a, 0)) {
        return solve_linear(coeffs.b, coeffs.c, &(solutions->x1));
    } else if (equal(discriminant, 0)) {
        solutions->x1 = (-coeffs.b) / (2.0 * coeffs.a);
        return 1;
    } else if (over(discriminant, 0)) {
        double sqrt_discr = sqrt(discriminant);
        solutions->x1 = (-coeffs.b + sqrt_discr) / (2.0 * coeffs.a);
        solutions->x2 = (-coeffs.b - sqrt_discr) / (2.0 * coeffs.a);
        return 2;
    }

    return 0;
}
