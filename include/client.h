/*!
 * \file
 * \brief Application client include file.
*/
#ifndef _CLIENT_H_
#define _CLIENT_H_
#include <cstddef>
#include "solve.h"

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
 * \warning It is a specific function for client application. 
 * Do not use it!
*/
void display_roots(const int n_roots, const square_solutions solutions);


#endif // _CLIENT_H_
