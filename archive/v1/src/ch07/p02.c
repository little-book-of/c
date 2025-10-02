#include <stdio.h>

int main(void) {
    int x = 5;
    int *p = &x;
    *p = 42;
    printf("x=%d *p=%d\n", x, *p);
    return 0;
}
