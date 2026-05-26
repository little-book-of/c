#include <stdio.h>
#include <string.h>

int main(void) {
    char dst[8];
    strncpy(dst, "Example", sizeof(dst) - 1);
    dst[sizeof(dst) - 1] = '\0';
    printf("Safe copy: %s\n", dst);
}
