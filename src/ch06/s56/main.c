/* Section 56: Linking Multiple Files — inlined into one standalone file. */
#include <stdio.h>

int add(int a, int b) { return a + b; }
int square(int x) { return x * x; }
int cube(int x) { return x * x * x; }

int main(void) {
    printf("add(3, 4)    = %d\n", add(3, 4));
    printf("square(5)    = %d\n", square(5));
    printf("cube(3)      = %d\n", cube(3));
    return 0;
}
