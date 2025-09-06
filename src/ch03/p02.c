#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    long long sq = (long long)n * n;
    long long cu = sq * n;
    printf("square=%lld cube=%lld\n", sq, cu);
    return 0;
}
