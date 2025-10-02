#include <stdio.h>

int main(void) {
    const int secret = 42;
    int g;
    while (1) {
        scanf("%d", &g);
        if (g == secret) { puts("Correct!"); break; }
        if (g < secret) puts("Too low");
        else puts("Too high");
    }
    return 0;
}
