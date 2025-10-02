#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    // Avoid overflow; return negative/0/positive
    return (x > y) - (x < y);
}

int main(void) {
    int arr[] = {4, 2, 5, 1, 3};
    size_t n = sizeof(arr)/sizeof(arr[0]);

    qsort(arr, n, sizeof(arr[0]), cmp_int);

    for (size_t i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
