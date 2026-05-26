/* Section 60: Write Your Own Makefile — inlined so no custom headers needed. */
#include <stdio.h>

int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }

int main(void) {
    printf("2 + 3 = %d\n", add(2, 3));
    printf("2 * 3 = %d\n", mul(2, 3));
    return 0;
}
