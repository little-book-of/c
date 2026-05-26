#include <stdio.h>

int main(void) {
    // for loop
    printf("for loop:\n");
    for (int i = 1; i <= 5; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    // while loop
    printf("while loop:\n");
    int n = 3;
    while (n > 0) {
        printf("n = %d\n", n);
        n--;
    }
    printf("\n");

    // do-while loop
    printf("do-while loop:\n");
    int x = 0;
    do {
        printf("x = %d\n", x);
        x++;
    } while (x < 1);
    printf("\n");

    // break and continue
    printf("break and continue demo:\n");
    for (int i = 1; i <= 10; i++) {
        if (i == 5) continue; // skip 5
        if (i == 8) break;    // stop at 8
        printf("%d ", i);
    }
    printf("\n");

    // nested loop
    printf("\nnested loops:\n");
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 3; j++) {
            printf("(%d,%d) ", i, j);
        }
        printf("\n");
    }

    return 0;
}
