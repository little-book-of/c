#include <stdio.h>

double area_circle(double r) { return 3.14159 * r * r; }

int main(void) {
    double r; while (scanf("%lf", &r) == 1) printf("r=%.3f area=%.5f\n", r, area_circle(r));
    return 0;
}
