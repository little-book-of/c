#include <stdlib.h>

void leak1(void) { malloc(100); }
void leak2(void) { char *p = malloc(50); free(p); }

int main(void) {
    leak1();
    leak2();
}
