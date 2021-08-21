#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <string.h>
#include "../include/quadratic.h"

const char *INITIAL_MSG = 
"╔═══╦╗─╔╦═══╦═══╦═══╦═══╦════╦══╦═══╗\n"
"║╔═╗║║─║║╔═╗╠╗╔╗║╔═╗║╔═╗║╔╗╔╗╠╣╠╣╔═╗║\n"
"║║─║║║─║║║─║║║║║║╚═╝║║─║╠╝║║╚╝║║║║─╚╝\n"
"║║─║║║─║║╚═╝║║║║║╔╗╔╣╚═╝║─║║──║║║║─╔╗\n"
"║╚═╝║╚═╝║╔═╗╠╝╚╝║║║╚╣╔═╗║─║║─╔╣╠╣╚═╝║\n"
"╚══╗╠═══╩╝─╚╩═══╩╝╚═╩╝─╚╝─╚╝─╚══╩═══╝\n"
"───╚╝ by d3phys.\n"
"\n"
"Commands:\n"
"(h or help) - print this message.\n"
"(q or quit) - exit.\n"
"Simply enter quadratic equation coeffitients a b c\n"
"Check docs https://github.com/d3phys/Quadratic\n\n\n";

const char *INCORRECT_MSG = "Incorrect input. Try again. Run (h) or (help).\n";

int client_square_eq() {
    square_params    params    = {0};
    square_solutions solutions = {0};

    char input[BUFFER_SIZE] = {0};
    char option = 0;

    printf("%s", INITIAL_MSG);

    size_t n_valid = 0;
    while (true) {
        fgets(input, BUFFER_SIZE, stdin);
        n_valid = sscanf(input, "%lf%lf%lf", &params.a, &params.b, &params.c);

        if(!strcmp(input, "q\n") || !strcmp(input, "quit\n")) {
            return 0;
        } else if (!strcmp(input, "h\n") || !strcmp(input, "help\n")) {
            printf("%s", INITIAL_MSG);
        } else if (n_valid == 3) {
            int n_roots = solve_quadratic(params, &solutions);
            display_roots(n_roots, solutions);
        } else {
            printf("%s", INCORRECT_MSG);
        }
    }

    return 0;
}
