#include <stdio.h>
#include <string.h>

int main(void) {
    char s1[100], s2[100];
    scanf("%99s %99s", s1, s2);
    int cmp = strcmp(s1, s2);
    if (cmp < 0) printf("%s\n", s1);
    else if (cmp > 0) printf("%s\n", s2);
    else printf("equal\n");
    return 0;
}
