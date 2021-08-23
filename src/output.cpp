#include <stdio.h>
#include "../include/client.h"
#include "../include/compare.h"

extern const int TOLERANCE_POWER;

/// [display_roots]
void display_roots(const int n_roots, const square_solutions solutions) {
    switch (n_roots) {
        case 0:
            printf("No real roots\n");
            break;
        case 1:
            printf("%*.*lf\n", TOLERANCE_POWER+1, TOLERANCE_POWER, solutions.x1);
            break;
        case 2:
            printf("%.*lf\n"
                   "%.*lf\n",  TOLERANCE_POWER, solutions.x1,
                               TOLERANCE_POWER, solutions.x2);
            break;
        case -1:
            printf("Any real number\n");
            break;
        default:
            printf("Something went wrong...\n");
    }
}
/// [display_roots]
