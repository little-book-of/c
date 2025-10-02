#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(void) {
    size_t n = 16;
    size_t align = 32;
    size_t bytes = n * sizeof(int);
    if (bytes % align) bytes += align - (bytes % align);  // size must be multiple of alignment

    int *a = aligned_alloc(align, bytes);
    if (!a) return 1;

    for (size_t i = 0; i < n; i++) a[i] = (int)i;
    printf("ptr=%p aligned_to_%zu? %s\n", (void*)a, align,
           ((uintptr_t)a % align == 0) ? "yes" : "no");

    free(a);
    return 0;
}
