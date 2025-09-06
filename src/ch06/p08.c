#include <stdio.h>

int main(void) {
    char s[] = "Hello";
    for (int i = 0; s[i] != '\0'; i++) printf("%c\n", s[i]);
    return 0;
}
