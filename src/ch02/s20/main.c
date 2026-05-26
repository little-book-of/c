#include <stdio.h>
#include <stdbool.h>

// Function declarations
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
void print_menu(void);

int main(void) {
    double num1, num2, result;
    char op;
    bool running = true;

    printf("=== Simple C Calculator ===\n");

    while (running) {
        print_menu();
        printf("Enter an operator (+, -, *, /) or q to quit: ");
        scanf(" %c", &op);

        if (op == 'q' || op == 'Q') {
            running = false;
            printf("Goodbye!\n");
            break;
        }

        printf("Enter first number: ");
        scanf("%lf", &num1);
        printf("Enter second number: ");
        scanf("%lf", &num2);

        switch (op) {
            case '+':
                result = add(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case '-':
                result = subtract(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case '*':
                result = multiply(num1, num2);
                printf("Result: %.2f\n", result);
                break;
            case '/':
                if (num2 == 0) {
                    printf("Error: Division by zero!\n");
                } else {
                    result = divide(num1, num2);
                    printf("Result: %.2f\n", result);
                }
                break;
            default:
                printf("Unknown operator: %c\n", op);
        }

        printf("\n");
    }

    return 0;
}

// Function definitions
double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

void print_menu(void) {
    printf("\nChoose an operation:\n");
    printf("  +  Addition\n");
    printf("  -  Subtraction\n");
    printf("  *  Multiplication\n");
    printf("  /  Division\n");
    printf("  q  Quit\n\n");
}
