#include <stdio.h>

int main(void) {
    int a = 10, b = 20;
    int *p = &a;
    printf("*p (a)=%d\n", *p);
    p = &b;
    printf("*p (b)=%d\n", *p);
    return 0;
}
