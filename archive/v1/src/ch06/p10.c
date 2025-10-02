#include <stdio.h>

int main(void) {
    char s[200];
    if (!fgets(s, sizeof(s), stdin)) return 0;
    int len = 0;
    while (s[len] != '\0' && s[len] != '\n') len++;
    printf("%d\n", len);
    return 0;
}
