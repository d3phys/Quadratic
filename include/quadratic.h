/*!
 * \file
 * \brief Main include file.
 */

#ifndef QUADRATIC_H_
#define QUADRATIC_H_

const double TOLERANCE = 1e-6;

/*!
 * \brief Parameters of a quadratic polynomial.
 * \details Holds coefficients of a polynomial which was rearranged in a standard form: 
 *
 * \f$ax^2+bx+c\f$
*/
struct square_params {
    double a;
    double b;
    double c;
};

/*!
 * \brief Solutions of the quadratic equation.
 * \details Holds solutions of the quadratic equation:
 *
 * \f$ax^2+bx+c=0\f$
*/
struct square_solutions {
    double x1;
    double x2;
};

int client_square_eq();

void display_roots(int n_roots, square_solutions solutions);

int solve_quadratic(square_params coeffs, square_solutions *solutions);
int solve_linear(double b, double c, double *solution);
double calc_discr(square_params coeffs); 

/*!
 * \brief Checks equality with tolerance.
 *
 * Compares two values. 
 * \param value1 First operand.
 * \param value2 Second operand.
 * \param tolerance Tolerance.
 * \code
 * equal(12.2, 21.0, 0.11); // false
 * equal(12.2, 21.0, 10.0); // true
 * \endcode
*/
bool equal(double value1, double value2, double tolerance = TOLERANCE);
bool over (double value1, double value2, double tolerance = TOLERANCE);
bool below(double value1, double value2, double tolerance = TOLERANCE);
#endif // QUADRATIC_H_
