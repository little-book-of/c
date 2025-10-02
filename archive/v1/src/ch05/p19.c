#include <stdio.h>
#include "mathlib.h"

int main(void) {
    int a = 12, b = 5;
    printf("add=%d sub=%d mul=%d div=%d sq=%d\n",
           add(a,b), sub(a,b), mul(a,b), div_int(a,b), square(a));
    return 0;
}
