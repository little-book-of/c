#include <stdio.h>
#include <stdlib.h>

void with_leak(void) {
    int *arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) arr[i] = i;
    printf("with_leak: allocated 5 ints, but not freed.\n");
}

void without_leak(void) {
    int *arr = malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) arr[i] = i;
    printf("without_leak: freeing memory.\n");
    free(arr);
}

int main(void) {
    with_leak();
    without_leak();
    return 0;
}
