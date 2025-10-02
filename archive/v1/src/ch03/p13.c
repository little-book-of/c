#include <stdio.h>

int main(void) {
    char c;
    scanf(" %c", &c);
    int is_upper = (c >= 'A' && c <= 'Z');
    int is_lower = (c >= 'a' && c <= 'z');
    printf("is_upper=%d is_lower=%d\n", is_upper, is_lower);
    return 0;
}
