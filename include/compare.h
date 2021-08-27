/*!
 * \file
 * \brief Tolerant computations include file.
 * \author d3phys
 * \date 27.08.2021
*/
#ifndef COMPARE_H_
#define COMPARE_H_

/*!
 * \brief Error
*/
const double TOLERANCE = 1e-12;

/*!
 * \brief Checks the guess about two double numbers.
 *
 * \param equal2    Presumably equal number
 * \param equal1    Presumably equal number
 * \param tolerance Tolerance
 *
 * \return Returns true if equal1 is equal to equal2 
 *
 * \code
 * check_equal(21.2, 21.0, 0.11); // false
 * check_equal(22.2, 21.0, 2.0);  // true
 * \endcode
*/
bool check_equal(const double equal1, const double equal2, const double tolerance = TOLERANCE);

/*!
 * \brief Checks the guess about two double numbers.
 *
 * \param greater   Presumably greater number
 * \param lower     Presumably lower number
 * \param tolerance Tolerance
 *
 * \return Returns true if greater is greater than lower
 *
 * \code
 * check_greater(21.2, 21.0, 0.11); // true
 * check_greater(22.2, 21.0, 2.0);  // false, because they are equal
 * \endcode
*/
bool check_greater(const double greater, const double lower, const double tolerance = TOLERANCE);


/*!
 * \brief Checks the guess about two double numbers.
 *
 * \param lower     Presumably lower number
 * \param greater   Presumably greater number
 * \param tolerance Tolerance
 *
 * \return Returns true if lower is lower than greater
 *
 * \code
 * check_lower(21.2, 21.0, 0.11); // false
 * check_lower(22.2, 21.0, 2.0);  // false, because they are equal
 * \endcode
*/
bool check_lower(const double lower, const double greater, const double tolerance = TOLERANCE);



#endif // COMPARE_H_
