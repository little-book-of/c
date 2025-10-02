#include <stdio.h>
#include <time.h>
int main(void){
    const int N = 100000000;
    clock_t t1=clock();
    long long s=0;
    for (int i=1;i<=N;i++) s+=i;
    clock_t t2=clock();
    printf("sum=%lld time=%.3f s\n", s,
           (double)(t2-t1)/CLOCKS_PER_SEC);
    return 0;
}
