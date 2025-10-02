#include <stdio.h>

int main(void) {
    char word[] = "Pointers";
    char *p = word;
    while (*p != '\0') {
        printf("%c\n", *p);
        p++;
    }
    return 0;
}
