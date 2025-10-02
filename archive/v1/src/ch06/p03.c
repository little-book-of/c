#include <stdio.h>

int main(void) {
    int a[8];
    for (int i = 0; i < 8; i++) scanf("%d", &a[i]);
    int mx = a[0];
    for (int i = 1; i < 8; i++) if (a[i] > mx) mx = a[i];
    printf("%d\n", mx);
    return 0;
}
