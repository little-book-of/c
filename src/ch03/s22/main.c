#include <stdio.h>

int main(void) {
    int number = 10;
    int *p = &number;  // pointer stores address of number

    printf("Value of number: %d\n", number);
    printf("Address of number: %p\n", (void *)&number);
    printf("Pointer p holds address: %p\n", (void *)p);
    printf("Value through pointer: %d\n", *p);

    *p = 20;  // modify the value via the pointer
    printf("New value of number: %d\n", number);

    return 0;
}
