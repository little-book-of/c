#include <stdio.h>
#include <stddef.h> // for NULL

int main(void) {
    int *p = NULL; // In C23 you may also use: int *p = nullptr;
    if (p == NULL) puts("Pointer is null");
    return 0;
}
