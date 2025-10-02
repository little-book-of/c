#include <stdio.h>
#include <string.h>

int main(void) {
    char src[] = "C programming";
    char dst[8];
    strncpy(dst, src, sizeof(dst) - 1);
    dst[sizeof(dst) - 1] = '\0';
    printf("%s\n", dst);
    return 0;
}
