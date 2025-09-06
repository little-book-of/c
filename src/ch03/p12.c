#include <stdio.h>

int main(void) {
    char c;
    scanf(" %c", &c);
    printf("char=%c code=%d next=%c prev=%c\n", c, (int)c, c + 1, c - 1);
    return 0;
}
