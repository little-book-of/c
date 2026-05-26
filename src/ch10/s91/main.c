/* Section 91: Designing Small C Libraries — simplemath inlined for standalone build. */
#include <stdio.h>

double sm_add(double a, double b) { return a + b; }
double sm_sub(double a, double b) { return a - b; }
double sm_mul(double a, double b) { return a * b; }
double sm_div(double a, double b, int *error) {
    if (b == 0.0) { *error = 1; return 0.0; }
    *error = 0;
    return a / b;
}

int main(void) {
    int err;
    double x = sm_div(10, 2, &err);
    printf("10 / 2 = %.2f\n", x);

    x = sm_div(10, 0, &err);
    if (err) printf("Error detected during division.\n");

    printf("add(3, 4) = %.2f\n", sm_add(3, 4));
    return 0;
}
