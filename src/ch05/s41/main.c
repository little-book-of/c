#include <stdio.h>

int main(void) {
    int i = 42;
    float f = 3.1415;
    char c = 'C';
    char *s = "Hello, C!";

    printf("Integer: %d\n", i);
    printf("Float: %.2f\n", f);
    printf("Char: %c\n", c);
    printf("String: %s\n", s);
    printf("Pointer: %p\n", (void*)s);
    return 0;
}
