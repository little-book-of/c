#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int p = (n > 0);
    printf("n>0 -> %d\n", p);
    printf("!(n>0) -> %d\n", !p);
    return 0;
}
