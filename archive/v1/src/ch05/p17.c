#include <stdio.h>

unsigned long long factorial(int n) {
    unsigned long long f = 1ULL;
    for (int i = 2; i <= n; i++) f *= (unsigned long long)i;
    return f;
}

int main(void) {
    for (int i = 1; i <= 10; i++) printf("%2d! = %llu\n", i, factorial(i));
    return 0;
}
