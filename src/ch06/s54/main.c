#include <stdio.h>

static inline int cube(int x) {
    return x * x * x;
}

int main(void) {
    int n = 3;
    printf("cube(%d) = %d\n", n, cube(n));
    return 0;
}
