#include <stdio.h>
#include <math.h>
static void show(double x){
    printf("x=% .2f ceil=% .2f floor=% .2f round=% .2f trunc=% .2f\n",
           x, ceil(x), floor(x), round(x), trunc(x));
}
int main(void){
    show(-2.7); show(2.7);
    return 0;
}
