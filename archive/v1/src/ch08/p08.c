#include <stdio.h>

typedef unsigned long long BigInt;

int main(void) {
    BigInt f = 1;
    for (int i = 2; i <= 10; i++) f *= (BigInt)i;
    printf("%llu\n", f);
    return 0;
}
