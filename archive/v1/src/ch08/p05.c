#include <stdio.h>

struct Rectangle { int width, height; };

int area(struct Rectangle r) { return r.width * r.height; }

int main(void) {
    struct Rectangle r = {5, 7};
    printf("%d\n", area(r));
    return 0;
}
