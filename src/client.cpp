#include <stdio.h>
#include <string.h>
#include "../include/client.h"
#include "../include/io.h"
#include "../include/config.h"

const char INITIAL_MSG[] = "╔═══╦╗─╔╦═══╦═══╦═══╦═══╦════╦══╦═══╗\n"
                           "║╔═╗║║─║║╔═╗╠╗╔╗║╔═╗║╔═╗║╔╗╔╗╠╣╠╣╔═╗║\n"
                           "║║─║║║─║║║─║║║║║║╚═╝║║─║╠╝║║╚╝║║║║─╚╝\n"
                           "║║─║║║─║║╚═╝║║║║║╔╗╔╣╚═╝║─║║──║║║║─╔╗\n"
                           "║╚═╝║╚═╝║╔═╗╠╝╚╝║║║╚╣╔═╗║─║║─╔╣╠╣╚═╝║\n"
                           "╚══╗╠═══╩╝─╚╩═══╩╝╚═╩╝─╚╝─╚╝─╚══╩═══╝\n"
                           "───╚╝A minimalistic equations solver\n"
                           "                           by d3phys\n";

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



int client_square_eq() {
    square_params    params    = {0};
    square_solutions solutions = {0};

    char input[INPUT_BUFFER] = {0};
    int  n_input = 0;

    set_color(YELLOW);
    printf("%s", INITIAL_MSG);
    set_color(RESET);

    size_t n_valid = 0;

    while (true) {
        set_color(YELLOW);
        printf("%s", INVITE_LINE);
        set_color(RESET);
        
        n_input = getl(input, INPUT_BUFFER, stdin);

        if (n_input < 0) {
            set_color(RED);
            printf("%s", OVERFLOW_MSG);
            set_color(RESET);
        } else {
            n_valid = sscanf(input, "%lf%lf%lf", &params.a, &params.b, &params.c);

            if(!strcmp(input, "q") || !strcmp(input, "quit")) {
                return 0;
            } else if (!strcmp(input, "h") || !strcmp(input, "help")) {
                set_color(BLUE);
                printf("%s", HELP_MSG);
                set_color(RESET);
            } else if (n_valid == 3) {
                int n_roots = solve_quadratic(params, &solutions);
                display_roots(n_roots, solutions);
            } else {
                set_color(RED);
                printf("%s", INCORRECT_MSG);
                set_color(RESET);
            }
        }
    }

    return 0;
}
