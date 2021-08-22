#ifndef QUADRATIC_H_
#define QUADRATIC_H_

const double TOLERANCE = 1e-6;

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

void display_roots(int n_roots, square_solutions solutions);

int solve_quadratic(square_params coeffs, square_solutions *solutions);
int solve_linear(double b, double c, double *solution);
double calc_discr(square_params coeffs); 

bool equal(double value1, double value2, double tolerance = TOLERANCE);
bool over (double value1, double value2, double tolerance = TOLERANCE);
bool below(double value1, double value2, double tolerance = TOLERANCE);
#endif // QUADRATIC_H_
