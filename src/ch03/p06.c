#include <stdio.h>

int main(void) {
    int x = 10, y;
    scanf("%d", &y);
    x += y; printf("x+=y -> %d\n", x);
    x -= y; printf("x-=y -> %d\n", x);
    x *= y; printf("x*=y -> %d\n", x);
    x /= y; printf("x/=y -> %d\n", x);
    x %= y; printf("x%%=y -> %d\n", x);
    return 0;
}
