/*!
 * \file
 * \brief Tolerant computations include file.
*/
#ifndef COMPARE_H_
#define COMPARE_H_
#include <math.h>

const double TOLERANCE = 1e-6;

/*!
 * \brief Checks equality with tolerance.
 *
 * Compares two numbers. 
 *
 * \param value1    First operand
 * \param value2    Second operand
 * \param tolerance Tolerance
 * 
 * \return Does value1 equal to value2
 *
 * \code
 * equal(12.2, 21.0, 0.11); // false
 * equal(12.2, 21.0, 10.0); // true
 * \endcode
*/
bool equal(const double value1, const double value2, const double tolerance = TOLERANCE);

/*!
 * \brief Compares two numbers.
 *
 * \param value1    First operand
 * \param value2    Second operand
 * \param tolerance Tolerance
 *
 * \return Is value1 greater than value2
 *
 * \code
 * over(21.2, 21.0, 0.11); // true
 * over(22.2, 21.0, 2.0);  // false, because they are equal
 * \endcode
*/
bool over (const double value1, const double value2, const double tolerance = TOLERANCE);

/*!
 * \brief Compares two numbers.
 *
 * \param value1    First operand
 * \param value2    Second operand
 * \param tolerance Tolerance
 *
 * \return Is value1 lower than value2
 *
 * \code
 * over(21.2, 21.0, 0.11); // false
 * over(22.2, 21.0, 2.0);  // false, because they are equal
 * \endcode
*/
bool below(const double value1, const double value2, const double tolerance = TOLERANCE);


#endif // COMPARE_H_
