#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    for (int r = 1; r <= n; r++) {
        for (int c = 1; c <= r; c++) {
            putchar('*');
        }
        putchar('\n');
    }
    return 0;
}
