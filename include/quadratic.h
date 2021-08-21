#ifndef QUADRATIC_H_
#define QUADRATIC_H_

const double DELTA = 1e-6;


struct square_params {
    double a;
    double b;
    double c;
};

struct square_solutions {
    double x1;
    double x2;
};

int client_square_eq();
int solve(square_params coeffs, square_solutions *solutions);

#endif // QUADRATIC_H_
