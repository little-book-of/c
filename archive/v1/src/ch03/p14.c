#include <stdio.h>

int main(void) {
    char c;
    scanf(" %c", &c);
    printf("%d\n", (c >= '0' && c <= '9'));
    return 0;
}
