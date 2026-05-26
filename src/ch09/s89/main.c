#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

[[nodiscard]] static inline uint32_t add(uint32_t a, uint32_t b) {
    return a + b;
}

int main(void) {
    const uint32_t x = 10, y = 20;
    uint32_t sum = add(x, y);

    bool valid = (sum > 0);
    if (valid)
        printf("Sum = %u\n", sum);

    return 0;
}
