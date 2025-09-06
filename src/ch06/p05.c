#include <stdio.h>

int main(void) {
    int a[10], cnt = 0;
    for (int i = 0; i < 10; i++) { scanf("%d", &a[i]); if (a[i] % 2 == 0) cnt++; }
    printf("%d\n", cnt);
    return 0;
}
