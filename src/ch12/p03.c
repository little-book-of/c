#include <stdio.h>
int main(void){
    puts(" n   n^2   n^3");
    for(int i=1;i<=10;i++)
        printf("%2d %5d %6d\n", i, i*i, i*i*i);
    return 0;
}
