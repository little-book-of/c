#include <stdio.h>
#include "p20_calc.h"
int main(void){
    printf("add=%d sub=%d mul=%d div=%d mod=%d pow=%d\n",
        add(7,3), sub(7,3), mul(7,3), div_int(7,3), mod(7,3), pow_int(2,10));
    return 0;
}
