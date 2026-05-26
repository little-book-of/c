#include <stdio.h>

struct DeviceStatus {
    unsigned int powered_on : 1;
    unsigned int connected  : 1;
    unsigned int has_error  : 1;
    unsigned int battery_low: 1;
    unsigned int reserved   : 4;
};

void print_bits(unsigned char byte) {
    for (int i = 7; i >= 0; i--)
        printf("%d", (byte >> i) & 1);
    printf("\n");
}

int main(void) {
    struct DeviceStatus d = {1, 1, 0, 0, 0};
    printf("Size of DeviceStatus: %zu bytes\n", sizeof(d));

    unsigned char *raw = (unsigned char*)&d;
    printf("Binary layout: ");
    print_bits(*raw);

    d.has_error = 1;
    printf("Updated binary: ");
    print_bits(*raw);

    return 0;
}
