#include <stdio.h>

int main(void) {
    int a = 10, b = 3;

    printf("a + b = %d\n", a + b);   // addition
    printf("a - b = %d\n", a - b);   // subtraction
    printf("a * b = %d\n", a * b);   // multiplication
    printf("a / b = %d\n", a / b);   // integer division
    printf("a %% b = %d\n", a % b);  // remainder (modulo)

    a += 5; // same as a = a + 5
    printf("a after += 5: %d\n", a);

    return 0;
}
