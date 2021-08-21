#include <stdio.h>
#include "quadratic.h"

const char *INITIAL_MSG = "[QUADRATIC EQUATION SOLVER]\n"
                          "ax^2 + bx + c = 0\n"
                          "Enter a b c coefficients:\n";

const char *INPUT_MSG = "Enter:\n";

const char *FINAL_MSG = "Solutions for the equation:\n";


int client_square_eq() {
    square_params    params    = {0};
    square_solutions solutions = {0};

    printf("%s", INITIAL_MSG);

    size_t n_valid = 0;
    while (n_valid != 3 || params.a == 0.0) {
        printf("%s", INPUT_MSG);
        n_valid = scanf("%lf%lf%lf", &params.a, &params.b, &params.c);
        scanf ("%*[^\n]");
    }


    size_t n_roots = solve(params, &solutions);

    printf("%s", FINAL_MSG);

    switch (n_roots) {
        case 0:
            printf("%s", "No solutions");
            break;
        case 1:
            printf("x1 = %lf\n", solutions.x1);
            break;
        case 2:
            printf("x1 = %lf\n"
                   "x2 = %lf\n", solutions.x1, solutions.x2);
            break;
        default:
            printf("%s", "Something went wrong...");
            break;
    }

    return 0;
}
