#include <stdio.h>

double area_rectangle(double w, double h) { return w * h; }
double perimeter_rectangle(double w, double h) { return 2.0 * (w + h); }

int main(void) {
    double w, h; scanf("%lf %lf", &w, &h);
    printf("area=%.3f perim=%.3f\n", area_rectangle(w,h), perimeter_rectangle(w,h));
    return 0;
}
