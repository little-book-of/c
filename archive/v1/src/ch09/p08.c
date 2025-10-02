#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(sizeof *p);
    if (!p) return 1;
    free(p);
    // free(p);              // ❌ double free
    p = NULL;                // ✅ fix: further free is harmless
    free(p);                 // OK (no-op)
    return 0;
}
