#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n = 10;
    int *a = malloc(n * sizeof *a);
    if (!a) return 1;
    for (size_t i = 0; i < n; i++) a[i] = (int)(i + 1);

    size_t m = 5;
    int *tmp = realloc(a, m * sizeof *a);
    if (!tmp) { free(a); return 1; }
    a = tmp; n = m;

    for (size_t i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}
