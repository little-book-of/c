#include <stdio.h>

struct Point { int x, y; };

int main(void) {
    struct Point p = {2, 3};
    struct Point *pp = &p;

    printf("(%d,%d)\n", pp->x, pp->y);
    pp->x = 10; pp->y = 20;
    printf("(%d,%d)\n", p.x, p.y);
    return 0;
}
