#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 3;
    int *nums = calloc(n, sizeof(int));

    if (nums == NULL) {
        printf("Initial allocation failed.\n");
        return 1;
    }

    // Fill array
    for (int i = 0; i < n; i++) nums[i] = (i + 1) * 5;

    printf("Initial values: ");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");

    // Resize
    n = 5;
    int *new_nums = realloc(nums, n * sizeof(int));
    if (new_nums == NULL) {
        printf("Reallocation failed.\n");
        free(nums);
        return 1;
    }
    nums = new_nums;

    // Fill new slots
    for (int i = 3; i < n; i++) nums[i] = (i + 1) * 5;

    printf("After realloc: ");
    for (int i = 0; i < n; i++) printf("%d ", nums[i]);
    printf("\n");

    free(nums);
    return 0;
}
