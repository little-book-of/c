#include <stdio.h>

int square(int n) { return n * n; }

int main(void) {
    for (int i = 1; i <= 10; i++) printf("%d^2 = %d\n", i, square(i));
    return 0;
}
