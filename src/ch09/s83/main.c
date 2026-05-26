/* Section 83: Inline Assembly — portable across x86-64 and ARM64. */
#include <stdio.h>

int add_fast(int a, int b) {
    int result;
#if defined(__x86_64__) || defined(__i386__)
    __asm__ ("addl %1, %0" : "=r"(result) : "r"(b), "0"(a));
#elif defined(__aarch64__)
    __asm__ ("add %w0, %w1, %w2" : "=r"(result) : "r"(a), "r"(b));
#else
    result = a + b;  /* portable fallback */
#endif
    return result;
}

int main(void) {
    printf("3 + 5 = %d\n", add_fast(3, 5));
    return 0;
}
