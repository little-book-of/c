#include <stdio.h>

int main(void) {
    int age = 25;              // integer
    float height = 1.75;       // floating-point number
    char initial = 'A';        // single character
    double weight = 68.4;      // double-precision number

    printf("Age: %d\n", age);
    printf("Height: %.2f\n", height);
    printf("Initial: %c\n", initial);
    printf("Weight: %.1lf\n", weight);

    return 0;
}
