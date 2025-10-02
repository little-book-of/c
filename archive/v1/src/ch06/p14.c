#include <stdio.h>
#include <string.h>

int main(void) {
    char src[100], dst[100];
    scanf("%99s", src);
    strcpy(dst, src);
    printf("src=%s dst=%s\n", src, dst);
    return 0;
}
