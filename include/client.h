/*!
 * \file
 * \brief Application client include file.
*/
#ifndef _CLIENT_H_
#define _CLIENT_H_
#include <cstddef>
#include <math.h>
#include "solve.h"

const char INITIAL_MSG[] = "╔═══╦╗─╔╦═══╦═══╦═══╦═══╦════╦══╦═══╗\n"
                           "║╔═╗║║─║║╔═╗╠╗╔╗║╔═╗║╔═╗║╔╗╔╗╠╣╠╣╔═╗║\n"
                           "║║─║║║─║║║─║║║║║║╚═╝║║─║╠╝║║╚╝║║║║─╚╝\n"
                           "║║─║║║─║║╚═╝║║║║║╔╗╔╣╚═╝║─║║──║║║║─╔╗\n"
                           "║╚═╝║╚═╝║╔═╗╠╝╚╝║║║╚╣╔═╗║─║║─╔╣╠╣╚═╝║\n"
                           "╚══╗╠═══╩╝─╚╩═══╩╝╚═╩╝─╚╝─╚╝─╚══╩═══╝\n"
                           "───╚╝A minimalistic equations solver.\n"
                           "                           by d3phys.\n";

const char INCORRECT_MSG[] = "Incorrect input. Try again. Run 'h' for help.\n";

const char OVERFLOW_MSG[] = "Buffer overflow. Try again. Run 'h' for help.\n";

const char HELP_MSG[] = "------------------------------------------------------\n"
                        "'h' or 'help'           - print this message.\n"
                        "'q' or 'quit'           - exit.\n"
                        "Enter 3 numbers (a b c) - solve ax²+bx+c=0 equation.\n"
                        "------------------------------------------------------\n"
                        "Buffer overflow error   - input length too long (>28).\n"
                        "Incorrect input error   - incorrect input.\n"
                        "------------------------------------------------------\n";

const char INVITE_LINE[] = "[quadratic]> ";

const size_t INPUT_BUFFER = 28;

const char INCORRECT_COLOR[]   = "\x1b[31m";
const char INITIAL_COLOR[]     = "\x1b[33m";
const char INVITE_LINE_COLOR[] = "\x1b[33m";
const char HELP_COLOR[]        = "\x1b[0m";
const char RESET_COLOR[]       = "\x1b[0m";

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
