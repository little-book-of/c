#include <stdio.h>
#include <stdlib.h>

int *make_array(size_t n) {
    int *a = malloc(n * sizeof *a);
    if (!a) return NULL;
    for (size_t i = 0; i < n; i++) a[i] = (int)(i + 1);
    return a;                         // caller frees
}

int main(void) {
    size_t n = 6;
    int *a = make_array(n);
    if (!a) return 1;
    for (size_t i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}
