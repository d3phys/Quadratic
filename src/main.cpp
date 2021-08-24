#include "client.h"
#include "../include/test.h"

#define UNIT_TEST

int main() {
    client_square_eq();

#ifdef UNIT_TEST
    test_solve_quadratic();
#endif

    return 0;
}
