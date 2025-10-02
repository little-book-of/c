#include <stdio.h>

struct Point { int x, y; };

int main(void) {
    struct Point p;
    p.x = 3; p.y = 4;
    printf("(%d,%d)\n", p.x, p.y);
    return 0;
}
