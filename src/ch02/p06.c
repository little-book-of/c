#include <stdio.h>

int main(void) {
    int a, b, t;
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);
    printf("Before: a=%d, b=%d\n", a, b);
    t = a; a = b; b = t;
    printf("After : a=%d, b=%d\n", a, b);
    return 0;
}
