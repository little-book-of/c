#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = nullptr;                  // start null (C23)
    if (p == nullptr) puts("null before allocation");

    p = malloc(4 * sizeof *p);
    if (p == nullptr) return 1;
    for (int i = 0; i < 4; i++) p[i] = i * 10;
    for (int i = 0; i < 4; i++) printf("%d ", p[i]);
    printf("\n");
    free(p);
    p = nullptr;
    return 0;
}
