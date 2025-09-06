#include <stdio.h>

union Data {
    int i;
    float f;
};

int main(void) {
    union Data d;
    d.i = 42;
    printf("i=%d\n", d.i);
    d.f = 3.14f;   // overwrites same storage
    printf("f=%.2f\n", d.f);
    // d.i now unspecified; don't rely on it
    return 0;
}
