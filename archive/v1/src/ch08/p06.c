#include <stdio.h>

typedef struct { int x, y; } Point;

int main(void) {
    Point p = {8, 9};
    printf("(%d,%d)\n", p.x, p.y);
    return 0;
}
