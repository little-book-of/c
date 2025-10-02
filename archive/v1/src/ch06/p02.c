#include <stdio.h>

int main(void) {
    int a[5], sum = 0;
    for (int i = 0; i < 5; i++) { scanf("%d", &a[i]); sum += a[i]; }
    printf("%d\n", sum);
    return 0;
}
