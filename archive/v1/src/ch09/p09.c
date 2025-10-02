#include <stdio.h>
#include <stdlib.h>

int main(void) {
    for (int i = 0; i < 10000; i++) {
        int *p = malloc(1000 * sizeof *p);
        if (!p) break;
        // ❌ leak if we forget to free
        free(p);             // ✅ fix leak
    }
    puts("Loop done without leaking.");
    return 0;
}
