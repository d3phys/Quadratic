#include <stdio.h>
#include "../include/solve.h"
#include "../include/compare.h"
#include "../include/test.h"
#include <string.h>

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
    int n_roots = 0;

    display_unit_init("test_solve_quadratic");

    n_roots = solve_quadratic({0, 0, 93.112}, &solutions);
    if ((succeed = (n_roots == 0)))
        n_succeed++;
    display_test(++n_tests, succeed);

    n_roots = solve_quadratic({0, 4.32, 2.93}, &solutions);
    if ((succeed = (n_roots == 1 && equal(solutions.x1, -0.678240741))))
        n_succeed++;
    display_test(++n_tests, succeed);

    n_roots = solve_quadratic({2.5, 54, 3.5}, &solutions);
    if ((succeed = (n_roots == 2 && equal(solutions.x1, -0.0650104797) 
                                 && equal(solutions.x2, -21.5349895  ))))
        n_succeed++;
    display_test(++n_tests, succeed);

    n_roots = solve_quadratic({2, 4, 2}, &solutions);
    if ((succeed = (n_roots == 1 && equal(solutions.x1, -1))))
        n_succeed++;
    display_test(++n_tests, succeed);

    n_roots = solve_quadratic({2, 4, 68.32}, &solutions);
    if ((succeed = (n_roots == 0)))
        n_succeed++;
    display_test(++n_tests, succeed);

    n_roots = solve_quadratic({0, 0, 0}, &solutions);
    if ((succeed = (n_roots == -1)))
        n_succeed++;
    display_test(++n_tests, succeed);

    display_unit_result(n_tests, n_succeed, n_tests - n_succeed);
}
