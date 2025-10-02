#include <stdio.h>

int main(void) {
    int a[10];
    for (int i = 0; i < 10; i++) scanf("%d", &a[i]);
    for (int i = 9; i >= 0; i--) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
