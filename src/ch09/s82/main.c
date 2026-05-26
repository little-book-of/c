#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>

int main(void) {
    FILE *f = fopen("num.bin", "wb");
    uint32_t n = 0x12345678;
    uint32_t net = htonl(n);
    fwrite(&net, sizeof(net), 1, f);
    fclose(f);

    f = fopen("num.bin", "rb");
    uint32_t read_net;
    fread(&read_net, sizeof(read_net), 1, f);
    fclose(f);
    printf("Read back: 0x%x\n", ntohl(read_net));
}
