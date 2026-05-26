/* Section 59: Understanding the Object File — standalone demo. */
#include <stdio.h>

int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }

int main(void) {
    printf("add(6, 7) = %d\n", add(6, 7));
    printf("mul(6, 7) = %d\n", mul(6, 7));
    return 0;
}
