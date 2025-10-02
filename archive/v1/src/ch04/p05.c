#include <stdio.h>

int main(void) {
    int a, b;
    char op;
    scanf("%d %d %c", &a, &b, &op);
    switch (op) {
        case '+': printf("%d\n", a + b); break;
        case '-': printf("%d\n", a - b); break;
        case '*': printf("%d\n", a * b); break;
        case '/':
            if (b == 0) printf("Error: divide by zero\n");
            else printf("%d\n", a / b);
            break;
        default: printf("Unknown operator\n");
    }
    return 0;
}
