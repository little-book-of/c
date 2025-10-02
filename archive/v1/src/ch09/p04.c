#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n; if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = malloc((size_t)n * sizeof *a);
    if (!a) return 1;
    for (int i = 0; i < n; i++) a[i] = i + 1;
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}
