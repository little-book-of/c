#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n = 8;
    int *m = malloc(n * sizeof *m);
    int *c = calloc(n, sizeof *c);
    if (!m || !c) return 1;

    printf("malloc contents (indeterminate/garbage): ");
    for (size_t i = 0; i < n; i++) printf("%d ", m[i]);  // reading uninitialized is UB in strict sense; just show addresses instead:
    printf("\n(avoid reading uninitialized; shown only to illustrate)\n");

    printf("calloc contents (zeroed): ");
    for (size_t i = 0; i < n; i++) printf("%d ", c[i]);
    printf("\n");

    free(m); free(c);
    return 0;
}
