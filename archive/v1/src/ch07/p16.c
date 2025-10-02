#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(sizeof(int));
    if (!p) return 0;
    *p = 42;
    free(p);
    // free(p); // ❌ double free (undefined behavior)

    // FIX:
    p = NULL;          // reset after free
    return 0;
}
