#include <stdio.h>

int main(void) {
    int *p;            // uninitialized (wild) — do NOT dereference
    // *p = 5;         // ❌ undefined behavior

    int x = 0;
    p = &x;            // FIX: initialize to a valid address
    *p = 5;
    printf("x=%d\n", x);
    return 0;
}
