#include <stdio.h>
#include <math.h>
int main(void){
    double a,b;
    if (scanf("%lf %lf",&a,&b)==2) printf("c=%.6f\n", hypot(a,b));
    return 0;
}
