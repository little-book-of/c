#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    while (n >= 1) {
        printf("%d\n", n);
        n = n - 1;
    }
    puts("Blast off!");
    return 0;
}
