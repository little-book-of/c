#include <stdio.h>

double average3(int a, int b, int c) { return (a + b + c) / 3.0; }

int main(void) {
    int a, b, c; scanf("%d %d %d", &a, &b, &c);
    printf("%.6f\n", average3(a, b, c));
    return 0;
}
