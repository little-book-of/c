#include <stdio.h>

long long sum_range(int a, int b) {
    long long s = 0;
    for (int i = a; i <= b; i++) s += i;
    return s;
}

int main(void) {
    int a, b; scanf("%d %d", &a, &b);
    printf("%lld\n", sum_range(a, b));
    return 0;
}
