#include <math.h>
#include <assert.h>
#include "../include/solve.h"
#include "../include/compare.h"

double calc_discr(const square_params coeffs) {
    return coeffs.b * coeffs.b - 4 * coeffs.a * coeffs.c;
}

roots_state solve_linear(const double b, const double c, double *solution) {
    assert(solution);

    if (check_equal(b, 0)) {
        if (check_equal(c, 0))
            return INF_RT;
        else 
            return ZERO_RT;
    } else {
        *solution = (-c) / b;

        if (!isfinite(*solution)) 
            return ERR_INF;

        return ONE_RT;
    }
}

roots_state solve_quadratic(const square_params coeffs, square_solutions *solutions) {
    assert(solutions);

    if (check_equal(coeffs.a, 0)) {
        return solve_linear(coeffs.b, coeffs.c, &(solutions->x1));
    } else if (check_equal(coeffs.c, 0)) {
        solutions->x1 = 0;
       
        if (solve_linear(coeffs.a, coeffs.b, &solutions->x2) == ERR_INF)
            return ERR_INF;

        return TWO_RT;
    } else {
        double sqrt_discr= sqrt(calc_discr(coeffs));

        if (check_equal(sqrt_discr, 0)) {
            solutions->x1 = (-coeffs.b) / (2.0 * coeffs.a);

            if (!isfinite(solutions->x1)) 
                return ERR_INF;

            return ONE_RT;
        } else if (check_greater(sqrt_discr, 0)) {
            solutions->x1 = (-coeffs.b + sqrt_discr) / (2.0 * coeffs.a);
            solutions->x2 = (-coeffs.b - sqrt_discr) / (2.0 * coeffs.a);

            if (!isfinite(solutions->x1) || !isfinite(solutions->x2))
                return ERR_INF;

            return TWO_RT;
        }
    }

    return ZERO_RT;
}
