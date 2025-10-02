#include <stdio.h>

int square(int x) { return x * x; }
int cube(int x)   { return x * x * x; }

int main(void) {
    int (*fp)(int) = square;
    printf("square(4)=%d\n", fp(4));
    fp = cube;
    printf("cube(3)=%d\n", fp(3));
    return 0;
}
