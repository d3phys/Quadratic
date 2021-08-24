/*!
 * \file
 * \brief Application client include file.
 * \author d3phys
 * \date 24.08.2021
*/
#ifndef _CLIENT_H_
#define _CLIENT_H_

#include "../include/solve.h"

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
void display_roots(const roots_state rs, const square_solutions solutions);


#endif // _CLIENT_H_
