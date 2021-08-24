#include "client.h"
#include "../include/test.h"

#define UNIT_TEST

int main() {

#ifdef UNIT_TEST
    test_solve_quadratic();
#endif

    client_square_eq();

    return 0;
}
