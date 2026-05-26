#include <stdio.h>

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

void operate(int x, int y, int (*op)(int, int)) {
    printf("Result: %d\n", op(x, y)); // call through pointer
}

int main(void) {
    int (*f)(int, int); // declaration

    f = add;
    printf("Add via pointer: %d\n", f(5, 3));

    f = sub;
    printf("Subtract via pointer: %d\n", f(5, 3));

    printf("\nUsing callback function:\n");
    operate(4, 6, mul); // pass function pointer as argument

    return 0;
}
