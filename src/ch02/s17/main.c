#include <stdio.h>

int global_var = 10; // global scope

void demo_scope(void) {
    int local_var = 5; // block scope
    static int persistent = 0; // retains value between calls

    printf("Global: %d, Local: %d, Static: %d\n", global_var, local_var, persistent);
    persistent++;
}

int main(void) {
    printf("First call:\n");
    demo_scope();

    printf("\nSecond call:\n");
    demo_scope();

    printf("\nAccessing global variable in main: %d\n", global_var);
    return 0;
}
