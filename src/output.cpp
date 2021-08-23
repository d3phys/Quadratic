#include <stdio.h>
#include "../include/client.h"
#include "../include/compare.h"

extern const double TOLERANCE;
const int OUT_DIGITS = (int) -log10(TOLERANCE);

void display_roots(const int n_roots, const square_solutions solutions) {

    switch (n_roots) {
        case 0:
            printf("No real roots\n");
            break;
        case 1:
            printf("%.*lf\n", OUT_DIGITS, solutions.x1);
            break;
        case 2:
            printf("%.*lf\n"
                   "%.*lf\n", OUT_DIGITS, solutions.x1,
                              OUT_DIGITS, solutions.x2);
            break;
        case -1:
            printf("Any real number\n");
            break;
        default:
            printf("Something went wrong...\n");
    }
}
