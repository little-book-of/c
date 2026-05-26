/* Section 55: Makefiles — inline add() so no custom header needed. */
#include <stdio.h>

int add(int a, int b) { return a + b; }

int main(void) {
    printf("2 + 3 = %d\n", add(2, 3));
    return 0;
}
