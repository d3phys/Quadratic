#include <stdio.h>
#include <string.h>
#include "client.h"
#include "../include/io.h"
#include "config.h"

#define CHECK_CMD(str1, str2)                    \
    strncmp(str1, str2, INPUT_BUFFER_SIZE) == 0  \

#define COLOR_PRINT(msg, color) \
    set_text_color(color);      \
    printf("%s", msg);          \
    reset_color();

const char INITIAL_MSG[] = "╔═══╦╗─╔╦═══╦═══╦═══╦═══╦════╦══╦═══╗\n"
                           "║╔═╗║║─║║╔═╗╠╗╔╗║╔═╗║╔═╗║╔╗╔╗╠╣╠╣╔═╗║\n"
                           "║║─║║║─║║║─║║║║║║╚═╝║║─║╠╝║║╚╝║║║║─╚╝\n"
                           "║║─║║║─║║╚═╝║║║║║╔╗╔╣╚═╝║─║║──║║║║─╔╗\n"
                           "║╚═╝║╚═╝║╔═╗╠╝╚╝║║║╚╣╔═╗║─║║─╔╣╠╣╚═╝║\n"
                           "╚══╗╠═══╩╝─╚╩═══╩╝╚═╩╝─╚╝─╚╝─╚══╩═══╝\n"
                           "───╚╝A minimalistic equations solver \n"
                           "                           by d3phys \n"
                           "Enter 3 numbers (a b c):             \n";

const char INCORRECT_MSG[] = "Incorrect input. Try again. Run 'h' for help.\n";

const char OVERFLOW_MSG[]  = "Buffer overflow. Try again. Run 'h' for help.\n";

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

    char input[INPUT_BUFFER_SIZE] = {0};
    int  n_chars_read = 0;

    COLOR_PRINT(INITIAL_MSG, YELLOW);

    size_t n_valid = 0;

    while (true) {
        COLOR_PRINT(INVITE_LINE, YELLOW);
        
        n_chars_read = getl(input, INPUT_BUFFER_SIZE, stdin);

        if (n_chars_read < 0) {
            COLOR_PRINT(OVERFLOW_MSG, RED);
        } else {
            n_valid = sscanf(input, "%lf%lf%lf", &params.a, &params.b, &params.c);

            if (CHECK_CMD(input, "q") || CHECK_CMD(input, "quit")) {
                return 0;
            } else if (CHECK_CMD(input, "h") || CHECK_CMD(input, "help")) {
                COLOR_PRINT(HELP_MSG, BLUE);
            } else if (n_valid == 3) {
                roots_state rs = solve_quadratic(params, &solutions);
                display_roots(rs, solutions);
            } else {
                COLOR_PRINT(INCORRECT_MSG, RED);
            }
        }
    }

    return 0;
}
