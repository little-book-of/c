#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    int avg_int = (a + b) / 2;
    double avg_f = (a + b) / 2.0;
    printf("avg_int=%d\n", avg_int);
    printf("avg_float=%.6f\n", avg_f);
    return 0;
}
