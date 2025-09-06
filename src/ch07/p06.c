#include <stdio.h>

int main(void) {
    int a[5];
    for (int i = 0; i < 5; i++) scanf("%d", &a[i]);
    int *p = a;
    int *end = a + 5;
    long long sum = 0;
    while (p < end) sum += *p++;
    printf("%lld\n", sum);
    return 0;
}
