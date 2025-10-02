#include <stdio.h>

int main(void) {
    int n;
    printf("Favorite integer: ");
    scanf("%d", &n);
    long long sq = (long long)n * n;
    long long cube = sq * n;
    printf("%d squared = %lld, cubed = %lld\n", n, sq, cube);
    return 0;
}
