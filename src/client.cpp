#include <stdio.h>
#include <string.h>
#include "../include/solve.h"
#include "../include/client.h"
#include "../include/compare.h"
#include "../include/io.h"
#include <assert.h>

int client_square_eq() {
    square_params    params    = {0};
    square_solutions solutions = {0};

    char input[INPUT_BUFFER] = {0};
    int n_input = 0;

    printf("%s%s%s", INITIAL_COLOR, INITIAL_MSG, RESET_COLOR);

    size_t n_valid = 0;

    while (true) {
        printf("%s%s%s", INVITE_LINE_COLOR, INVITE_LINE, RESET_COLOR);
        
        n_input = getl(input, INPUT_BUFFER, stdin);

        if (n_input < 0) {
            printf("%s%s%s", INCORRECT_COLOR, OVERFLOW_MSG, RESET_COLOR);
        } else {
            n_valid = sscanf(input, "%lf%lf%lf", &params.a, &params.b, &params.c);

            if(!strcmp(input, "q") || !strcmp(input, "quit")) {
                return 0;
            } else if (!strcmp(input, "h") || !strcmp(input, "help")) {
                printf("%s%s%s", HELP_COLOR, HELP_MSG, RESET_COLOR);
            } else if (n_valid == 3) {
                int n_roots = solve_quadratic(params, &solutions);
                display_roots(n_roots, solutions);
            } else {
                printf("%s%s%s", INCORRECT_COLOR, INCORRECT_MSG, RESET_COLOR);
            }
        }
    }

    return 0;
}
