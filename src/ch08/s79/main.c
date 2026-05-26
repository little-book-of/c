/* Section 79: Code Review Checklist — common bugs to watch for. */
#include <stdio.h>
#include <stdlib.h>

/* GOOD: heap-allocated version — safe to return */
int *make_array(int n) {
    int *arr = malloc((size_t)n * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < n; i++) arr[i] = i;
    return arr;
}

int main(void) {
    int *a = make_array(5);
    if (!a) return 1;
    for (int i = 0; i < 5; i++) printf("%d ", a[i]);
    printf("\n");
    free(a);
    return 0;
}
