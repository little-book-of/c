#include <stdio.h>

int double_it(int n) { return 2 * n; }

int main(void) {
    for (int i = -2; i <= 2; i++) printf("%d -> %d\n", i, double_it(i));
    return 0;
}
