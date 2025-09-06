#include <stdio.h>

void demo(void) {
    int x = 42;                 // automatic (stack)
    printf("x=%d at %p\n", x, (void*)&x);
}

int main(void) {
    demo();
    demo();                     // new lifetime, likely different address
    return 0;
}
