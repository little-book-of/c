#include <stdio.h>

int main(void) {
    int arr[5] = {2, 4, 6, 8, 10};
    int *ptr = arr; // arr decays to pointer to arr[0]

    printf("Accessing with array index:\n");
    for (int i = 0; i < 5; i++) {
        printf("arr[%d] = %d\n", i, arr[i]);
    }

    printf("\nAccessing with pointer arithmetic:\n");
    for (int i = 0; i < 5; i++) {
        printf("*(ptr + %d) = %d\n", i, *(ptr + i));
    }

    printf("\nAddresses in memory:\n");
    for (int i = 0; i < 5; i++) {
        printf("&arr[%d] = %p\n", i, (void *)&arr[i]);
    }

    return 0;
}
