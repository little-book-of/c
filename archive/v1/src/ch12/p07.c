#include <stdio.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif
int main(void){
    double deg=45.0, rad = deg * (M_PI/180.0);
    printf("sin=%.6f cos=%.6f tan=%.6f\n", sin(rad), cos(rad), tan(rad));
    return 0;
}
