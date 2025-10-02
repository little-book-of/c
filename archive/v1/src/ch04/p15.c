#include <stdio.h>

int main(void) {
    for (int i = 1; i <= 100; i++) {
        if (i % 17 == 0) { printf("%d\n", i); break; }
    }
    return 0;
}
