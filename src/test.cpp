#include <stdio.h>
#include "../include/solve.h"
#include "../include/compare.h"
#include "../include/test.h"

#define TEST_SOLVE(a, b, c, expression)                \
    n_roots = solve_quadratic({a, b, c}, &solutions);  \
    succeed = expression;                              \
    if (succeed)                                       \
        n_succeed++;                                   \
    display_test(++n_tests, succeed);

const char SUCCESS[] = "\u001b[32m✔\u001b[0m";
const char FAILURE[] = "\u001b[31m✘\u001b[0m";

void display_unit_init(const char *unit) {
    printf("------------------------------------\n"
           "Unit: %29s\n"
           "------------------------------------\n", unit);
}

void display_unit_result(const size_t n_tests, const size_t n_succeed, const size_t n_failed) {
    printf("------------------------------------\n"
           "Tests:%3ld \u001b[32mSuccess: %3ld \u001b[31mFailure: %3ld \u001b[0m\n"
           "------------------------------------\n", n_tests, n_succeed, n_failed);
}

void display_test(const size_t test_number, const bool succeed) {
    printf("Test#%2ld: %s\n", test_number, succeed ? SUCCESS : FAILURE);
}

void test_solve_quadratic() {
    size_t n_tests   = 0;
    size_t n_succeed = 0;
    bool   succeed   = false;

    square_solutions solutions = {0};
    roots_state n_roots = INF_RT;

    display_unit_init("test_solve_quadratic");

    TEST_SOLVE(0, 0, 93.112,  (n_roots == ZERO_RT));

    TEST_SOLVE(0, 4.32, 2.93, (n_roots == ONE_RT && check_equal(solutions.x1, -0.678240740741)));

    TEST_SOLVE(2.5, 54, 3.50, (n_roots == TWO_RT && check_equal(solutions.x1, -0.065010479744) 
                                                 && check_equal(solutions.x2, -21.534989520256)));

    TEST_SOLVE(2, 4, 2, (n_roots == ONE_RT && check_equal(solutions.x1, -1)));

    TEST_SOLVE(2, 4, 68.32, (n_roots == ZERO_RT))

    TEST_SOLVE(0, 0, 0, (n_roots == INF_RT))

    TEST_SOLVE(TOLERANCE, -TOLERANCE, 0, (n_roots == TWO_RT && check_equal(solutions.x1, 0.0) 
                                                            && check_equal(solutions.x2, 1.0  )));

    TEST_SOLVE(TOLERANCE / 10, -TOLERANCE / 10, 0, (n_roots == INF_RT));


    display_unit_result(n_tests, n_succeed, n_tests - n_succeed);
}
