#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int main(void) {
    printf("add(3, 4)      = %d\n", add(3, 4));
    printf("multiply(3, 4) = %d\n", multiply(3, 4));
    return 0;
}
