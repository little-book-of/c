#include <stdio.h>

int main(void) {
    int *p;
    *p = 10;  // writing to uninitialized pointer
    printf("%d\n", *p);
}
