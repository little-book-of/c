#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n; if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = calloc((size_t)n, sizeof *a);      // zeroed
    if (!a) return 1;
    for (int i = 0; i < n; i++) printf("%d ", a[i]);  // shows zeros
    printf("\n");
    free(a);
    return 0;
}
