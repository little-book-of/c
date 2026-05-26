#include <stdio.h>
#include <stdbool.h>

// function declarations
int add(int x, int y);
double divide(double a, double b);
bool is_even(int n);
void greet(const char *name);

int main(void) {
    greet("C Programmer");

    int sum = add(7, 3);
    double quotient = divide(10.0, 4.0);
    bool check = is_even(sum);

    printf("Sum: %d\n", sum);
    printf("Quotient: %.2f\n", quotient);
    printf("Is sum even? %s\n", check ? "Yes" : "No");

    return 0;
}

// function definitions
int add(int x, int y) {
    return x + y;
}

double divide(double a, double b) {
    if (b == 0.0) {
        printf("Cannot divide by zero.\n");
        return 0.0;
    }
    return a / b;
}

bool is_even(int n) {
    return n % 2 == 0;
}

void greet(const char *name) {
    printf("Hello, %s!\n", name);
}
