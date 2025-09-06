#include <stdio.h>

int main(void) {
    int arr[10];
    int *p = arr;
    printf("sizeof(arr)=%zu\n", sizeof(arr));
    printf("sizeof(p)  =%zu\n", sizeof(p));
    return 0;
}
