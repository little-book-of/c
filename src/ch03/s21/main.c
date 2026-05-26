#include <stdio.h>
#include <stdlib.h>

// Global variable (Data segment)
int global_var = 42;

// Uninitialized global variable (BSS segment)
int global_bss;

void show_addresses(void) {
    // Local variable (Stack)
    int local_var = 10;

    // Static variable (Data segment)
    static int static_var = 20;

    // Dynamic variable (Heap)
    int *heap_var = malloc(sizeof(int));
    *heap_var = 30;

    printf("Code (function) address:     %p\n", (void *)show_addresses);
    printf("Global variable address:     %p\n", (void *)&global_var);
    printf("Uninitialized global address:%p\n", (void *)&global_bss);
    printf("Static variable address:     %p\n", (void *)&static_var);
    printf("Stack variable address:      %p\n", (void *)&local_var);
    printf("Heap variable address:       %p\n", (void *)heap_var);

    free(heap_var);
}

int main(void) {
    show_addresses();
    return 0;
}
