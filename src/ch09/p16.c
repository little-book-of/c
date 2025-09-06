#include <stdio.h>
#include <stdlib.h>

int main(void) {
    size_t n = 5;
    int *a = malloc(n * sizeof *a);
    if (!a) return 1;
    for (size_t i = 0; i < n; i++) a[i] = (int)(i + 1);

    size_t m = 10;
    int *tmp = realloc(a, m * sizeof *a);
    if (!tmp) { free(a); return 1; }
    a = tmp;

    for (size_t i = n; i < m; i++) a[i] = (int)((i + 1) * (i + 1)); // squares 6..10
    for (size_t i = 0; i < m; i++) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}
