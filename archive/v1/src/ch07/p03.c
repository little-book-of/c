#include <stdio.h>

int main(void) {
    int n = 7;
    int *p1 = &n, *p2 = &n;
    *p1 = 99;
    printf("*p2=%d (n=%d)\n", *p2, n);
    return 0;
}
