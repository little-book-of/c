#include <stdio.h>
#include <math.h>
int main(void){
    double P,r; int n;
    if (scanf("%lf %lf %d",&P,&r,&n)==3)
        printf("%.6f\n", P*pow(1.0+r, n));
    return 0;
}
