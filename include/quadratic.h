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
 * 
 * Holds solutions of the quadratic equation:
 *
 * \f$ax^2+bx+c=0\f$
*/
struct square_solutions {
    double x1;
    double x2;
};

/*!
 * \brief Main quadratic application client procedure.
 *
 * \return 
 * - 0          Success
 * - -1         Error
*/
int client_square_eq();

/*!
 * \brief Displays solutions.
 *
 * Code below.
 *
 * \snippet output.cpp display_roots
 * 
*/
void display_roots(int n_roots, square_solutions solutions);

/*!
 * \brief Solves quadratic equation.
 *
 * \f$ax^2+bx+c=0\f$
 *
 * Uses well known formula 
 *
 * \f$x_1 = \frac{-b + \sqrt{D}}{2a}\f$ and \f$x_2 = \frac{-b - \sqrt{D}}{2a}\f$
 * \param[in] coeffs Quadratic polynomial coefficients
 * \param[out] solutions Roots
 * \return Amount of roots
 *
 * \warning 
 * - if \f$a=b=c=0\f$ it returns -1
 * - if \f$a=b=0\f$ and \f$c!=0\f$ it returns 0
*/
int solve_quadratic(square_params coeffs, square_solutions *solutions);


/*!
 * \brief Solves linear equation.
 *
 * \f$bx+c=0\f$
 *
 * Uses well known formula 
 *
 * \f$x = -\frac{c}{b}\f$
 * \param[in] b coefficient
 * \param[in] c coefficient
 * \param[out] solution Root
 * \return Amount of roots
 *
 * \warning 
 * - if \f$b=c=0\f$ it returns -1
 * - if \f$b=0\f$ and \f$c!=0\f$ it returns 0
*/
int solve_linear(double b, double c, double *solution);


/*!
 * \brief Calculates the discriminant.
 *
 * Uses well known formula 
 *
 * \f$D=b^2-4ac\f$
 * \param coeffs Quadratic polynomial coefficients
 * \return Disctiminant
*/
double calc_discr(square_params coeffs); 

/*!
 * \brief Checks equality with tolerance.
 *
 * Compares two numbers. 
 * \param value1 First operand
 * \param value2 Second operand
 * \param tolerance Tolerance
 * \return Does value1 equal to value2
 * \code
 * equal(12.2, 21.0, 0.11); // false
 * equal(12.2, 21.0, 10.0); // true
 * \endcode
*/
bool equal(double value1, double value2, double tolerance = TOLERANCE);

/*!
 * \brief Compares two numbers.
 *
 * \param value1 First operand
 * \param value2 Second operand
 * \param tolerance Tolerance
 * \return Is value1 greater than value2
 * \code
 * over(21.2, 21.0, 0.11); // true
 * over(22.2, 21.0, 2.0); // false, because they are equal
 * \endcode
*/
bool over (double value1, double value2, double tolerance = TOLERANCE);

/*!
 * \brief Compares two numbers.
 *
 * \param value1 First operand
 * \param value2 Second operand
 * \param tolerance Tolerance
 * \return Is value1 lower than value2
 * \code
 * over(21.2, 21.0, 0.11); // false
 * over(22.2, 21.0, 2.0); // false, because they are equal
 * \endcode
*/
bool below(double value1, double value2, double tolerance = TOLERANCE);
#endif // QUADRATIC_H_
