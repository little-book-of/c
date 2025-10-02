#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", (a > 10) || (b > 10));
    return 0;
}
