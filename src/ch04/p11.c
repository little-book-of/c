#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    unsigned long long fact = 1ULL;
    for (int i = 1; i <= n; i++) fact *= i;
    printf("%llu\n", fact);
    return 0;
}
