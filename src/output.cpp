#include <stdio.h>
#include "../include/quadratic.h"

void display_roots(int n_roots, square_solutions solutions) {
    switch (n_roots) {
        case 0:
            printf("No real roots.\n");
            break;
        case 1:
            printf("x1 = %.6lf\n", solutions.x1);
            break;
        case 2:
            printf("x1 = %.6lf\n"
                   "x2 = %.6lf\n", solutions.x1, solutions.x2);
            break;
        case -1:
            printf("Any real number.\n");
            break;
        default:
            printf("Something went wrong...\n");
    }
}
