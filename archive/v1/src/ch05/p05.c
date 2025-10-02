#include <stdio.h>

int is_even(int n) { return (n % 2 == 0); }

int main(void) {
    for (int i = 1; i <= 10; i++) printf("%d -> %d\n", i, is_even(i));
    return 0;
}
