#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n = 5;
    int *a = malloc(n * sizeof *a);
    if (!a) return 1;
    for (size_t i = 0; i < n; i++) a[i] = (int)i;

    // printf("%d\n", a[5]); // ❌ OOB (6th element) — don't do this
    if (n > 5) printf("%d\n", a[5]); else puts("index 5 is out of bounds");
    free(a);
    return 0;
}
