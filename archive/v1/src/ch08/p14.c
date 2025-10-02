#include <stdio.h>

union U {
    char c[4];
    int n;
};

int main(void) {
    union U u;
    u.n = 0x12345678;  // endianness affects output
    printf("%02X %02X %02X %02X\n",
           (unsigned char)u.c[0],
           (unsigned char)u.c[1],
           (unsigned char)u.c[2],
           (unsigned char)u.c[3]);
    return 0;
}
