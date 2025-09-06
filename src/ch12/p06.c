#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
int main(void){
    double r; if (scanf("%lf",&r)!=1) return 0;
    double A = M_PI*r*r, C = 2*M_PI*r;
    printf("area=%.6f circ=%.6f\n", A, C);
    return 0;
}
