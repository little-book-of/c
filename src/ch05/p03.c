#include <stdio.h>

int max2(int a, int b) { return (a > b) ? a : b; }

int main(void) {
    int a, b; scanf("%d %d", &a, &b);
    printf("%d\n", max2(a, b));
    return 0;
}
