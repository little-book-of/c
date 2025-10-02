#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void) {
    printf("int:     %d .. %d\n", INT_MIN, INT_MAX);
    printf("uint:    0 .. %u\n", UINT_MAX);
    printf("float:   %e .. %e\n", FLT_MIN, FLT_MAX);
    printf("double:  %e .. %e\n", DBL_MIN, DBL_MAX);
    return 0;
}
