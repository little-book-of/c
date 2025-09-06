#include <stdio.h>
#include <time.h>
#define CUBE_MACRO(x) ((x)*(x)*(x))
inline int cube_inline(int x){ return x*x*x; }

int main(void){
    volatile int s=0;
    const int N=1000000;
    clock_t t1=clock();
    for(int i=0;i<N;i++) s+=CUBE_MACRO(i%100);
    clock_t t2=clock();
    for(int i=0;i<N;i++) s+=cube_inline(i%100);
    clock_t t3=clock();
    printf("macro: %.3f ms\n", 1000.0*(t2-t1)/CLOCKS_PER_SEC);
    printf("inline: %.3f ms\n", 1000.0*(t3-t2)/CLOCKS_PER_SEC);
    printf("s=%d\n", s);
    return 0;
}
