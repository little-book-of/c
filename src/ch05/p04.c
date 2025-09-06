#include <stdio.h>

int min3(int a, int b, int c) {
    int m = a;
    if (b < m) m = b;
    if (c < m) m = c;
    return m;
}

int main(void) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", min3(a, b, c));
    return 0;
}
