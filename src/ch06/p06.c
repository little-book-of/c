#include <stdio.h>

int main(void) {
    int a[10]; long long sum = 0;
    for (int i = 0; i < 10; i++) { scanf("%d", &a[i]); sum += a[i]; }
    printf("%.6f\n", (double)sum / 10.0);
    return 0;
}
