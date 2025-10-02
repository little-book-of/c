#include <stdio.h>

int main(void) {
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) break;
        if (n < 0) continue;
        printf("%d\n", n);
    }
    return 0;
}
