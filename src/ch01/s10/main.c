/* Section 10: Practice — Build Your First Multi-File Project.
   Self-contained version: in a real project this would be split into
   greet.h, greet.c, calc.h, calc.c, and main.c (see Section 9). */
#include <stdio.h>

/* --- "greet" module --- */
void greet(const char *name) {
    printf("Hello, %s!\n", name);
}

/* --- "calc" module --- */
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }

/* --- entry point --- */
int main(void) {
    greet("C Learner");
    printf("2 + 3 = %d\n", add(2, 3));
    printf("7 - 4 = %d\n", sub(7, 4));
    printf("6 * 5 = %d\n", mul(6, 5));
    return 0;
}
