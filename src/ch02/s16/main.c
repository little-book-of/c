#include <stdio.h>

// function declarations
int add(int a, int b);
int subtract(int a, int b);
double divide(double a, double b);
void greet(const char *name);

// main function
int main(void) {
    greet("C Learner");

    int sum = add(10, 5);
    int diff = subtract(10, 5);
    double quotient = divide(10.0, 5.0);

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Quotient: %.2f\n", quotient);

    return 0;
}

// function definitions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

double divide(double a, double b) {
    if (b == 0) {
        printf("Error: division by zero!\n");
        return 0.0;
    }
    return a / b;
}

void greet(const char *name) {
    printf("Hello, %s!\n", name);
}
