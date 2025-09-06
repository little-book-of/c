#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", n % 2);  // 0 even, 1 odd (for non-negative n)
    return 0;
}
