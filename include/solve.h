#ifndef SOLVE_H_
#define SOLVE_H_

/*!
 * \brief Parameters of the quadratic polynomial.
 *
 * Holds coefficients of the polynomial which was rearranged in a standard form: 
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
 * \brief Solves quadratic equation.
 *
 * \f$ax^2+bx+c=0\f$
 *
 * Uses well known formula 
 *
 * \f$x_1 = \frac{-b + \sqrt{D}}{2a}\f$ and \f$x_2 = \frac{-b - \sqrt{D}}{2a}\f$
 *
 * \param[in]  coeffs    Quadratic polynomial coefficients
 * \param[out] solutions Roots
 *
 * \return Amount of roots
 *
 * \warning 
 * - if \f$a=b=c=0\f$ it returns -1
 * - if \f$a=b=0\f$ and \f$c!=0\f$ it returns 0
*/
int solve_quadratic(const square_params coeffs, square_solutions *solutions);

/*!
 * \brief Solves linear equation.
 *
 * \f$bx+c=0\f$
 *
 * Uses well known formula 
 *
 * \f$x = -\frac{c}{b}\f$
 *
 * \param[in]  b        coefficient
 * \param[in]  c        coefficient
 * \param[out] solution Root
 *
 * \return Amount of roots
 *
 * \warning 
 * - if \f$b=c=0\f$ it returns -1
 * - if \f$b=0\f$ and \f$c!=0\f$ it returns 0
*/
int solve_linear(const double b, const double c, double *solution);

/*!
 * \brief Calculates the discriminant.
 *
 * Uses well known formula 
 *
 * \f$D=b^2-4ac\f$
 * 
 * \param coeffs Quadratic polynomial coefficients
 *
 * \return Discriminant
*/
double calc_discr(const square_params coeffs); 


#endif //SOLVE_H_
