#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
    srand((unsigned)time(NULL));
    double sum=0.0;
    for(int i=0;i<100;i++){
        double r = (double)rand() / (RAND_MAX + 1.0);
        sum += r;
    }
    printf("avg=%.6f\n", sum/100.0);
    return 0;
}
