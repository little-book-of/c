#include <stdio.h>

int main(void) {
    char a, b, c;
    printf("Enter your initials (e.g., A B C): ");
    scanf(" %c %c %c", &a, &b, &c);
    printf("Your initials are: %c%c%c\n", a, b, c);
    return 0;
}
