#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    if (n > 0) printf("Positive\n");
    else if (n < 0) printf("Negative\n");
    else printf("Zero\n");
    return 0;
}
