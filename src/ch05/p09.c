#include <stdio.h>

double c_to_f(double c) { return c * 9.0 / 5.0 + 32.0; }

int main(void) {
    double c; while (scanf("%lf", &c) == 1) printf("%.2f C = %.2f F\n", c, c_to_f(c));
    return 0;
}
