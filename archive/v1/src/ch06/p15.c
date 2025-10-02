#include <stdio.h>
#include <string.h>

int main(void) {
    char a[32] = "Hello";
    char b[] = "World";
    strcat(a, b);
    printf("%s\n", a);
    return 0;
}
