#include <stdio.h>

int main(void) {
#if defined(__x86_64__)
    printf("x86_64\n");
#elif defined(__aarch64__)
    printf("ARM64\n");
#elif defined(__arm__)
    printf("ARM 32-bit\n");
#elif defined(__riscv)
    printf("RISC-V\n");
#else
    printf("Unknown architecture\n");
#endif
}
