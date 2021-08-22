#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include "../include/quadratic.h"
#include "../include/colors.h"

const char *INITIAL_MSG = ANSI_COLOR_YELLOW "╔═══╦╗─╔╦═══╦═══╦═══╦═══╦════╦══╦═══╗\n"
                                            "║╔═╗║║─║║╔═╗╠╗╔╗║╔═╗║╔═╗║╔╗╔╗╠╣╠╣╔═╗║\n"
                                            "║║─║║║─║║║─║║║║║║╚═╝║║─║╠╝║║╚╝║║║║─╚╝\n"
                                            "║║─║║║─║║╚═╝║║║║║╔╗╔╣╚═╝║─║║──║║║║─╔╗\n"
                                            "║╚═╝║╚═╝║╔═╗╠╝╚╝║║║╚╣╔═╗║─║║─╔╣╠╣╚═╝║\n"
                                            "╚══╗╠═══╩╝─╚╩═══╩╝╚═╩╝─╚╝─╚╝─╚══╩═══╝\n"
                                            "───╚╝A minimalistic equations solver.\n"
                                            "                           by d3phys.\n" ANSI_COLOR_RESET;

const char *INCORRECT_MSG = ANSI_COLOR_RED "Incorrect input. Try again. Run (h) or (help).\n" ANSI_COLOR_RESET;

const char *HELP_MSG =  "(h or help) - print this message.\n"
                        "(q or quit) - exit.\n"
                        "Simply enter quadratic equation coeffitients a b c\n"
                        "Check README.md\n"
                        "https://github.com/d3phys/Quadratic\n";

const char *INVITE_LINE = ANSI_COLOR_YELLOW "[quadratic]# " ANSI_COLOR_RESET;

const size_t INPUT_BUFFER = 30;

/*!
 * \brief Short description.
 * Short
 *             
 *
 * Long description.
 *                            
 *                              
 *                              */
int client_square_eq() {
    square_params    params    = {0};
    square_solutions solutions = {0};

    char input[INPUT_BUFFER] = {0};
    char option = 0;

    printf("%s", INITIAL_MSG);

    size_t n_valid = 0;
    while (true) {
        printf("%s", INVITE_LINE);
        fgets(input, INPUT_BUFFER, stdin);
        n_valid = sscanf(input, "%lf%lf%lf", &params.a, &params.b, &params.c);

        if(!strcmp(input, "q\n") || !strcmp(input, "quit\n")) {
            return 0;
        } else if (!strcmp(input, "h\n") || !strcmp(input, "help\n")) {
            printf("%s", HELP_MSG);
        } else if (n_valid == 3) {
            int n_roots = solve_quadratic(params, &solutions);
            display_roots(n_roots, solutions);
        } else {
            printf("%s", INCORRECT_MSG);
        }
    }

    return 0;
}
