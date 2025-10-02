#include <stdio.h>

int main(void) {
    char c;
    printf("Enter a character: ");
    scanf(" %c", &c);
    printf("You entered: %c\nASCII code: %d\n", c, (int)c);
    return 0;
}
