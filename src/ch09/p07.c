#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p = malloc(sizeof *p);
    if (!p) return 1;
    *p = 99;
    free(p);
    // *p = 5;               // ❌ use-after-free
    p = NULL;                 // ✅ fix
    if (p == NULL) puts("Pointer reset to NULL");
    return 0;
}
