#include <stdio.h>

struct Point { int x, y; };

int main(void) {
    struct Point pts[3] = { {1,2}, {3,4}, {5,6} };
    for (int i = 0; i < 3; i++)
        printf("(%d,%d)\n", pts[i].x, pts[i].y);
    return 0;
}
