#include <stdio.h>

int square(int x) { return x * x; }
int cube(int x)   { return x * x * x; }

void apply(int (*f)(int), int x) {
    printf("%d\n", f(x));
}

int main(void) {
    apply(square, 5);
    apply(cube, 4);
    return 0;
}
