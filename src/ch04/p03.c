#include <stdio.h>

int main(void) {
    int score;
    scanf("%d", &score);
    if (score >= 90) printf("A\n");
    else if (score >= 75) printf("B\n");
    else if (score >= 50) printf("C\n");
    else printf("F\n");
    return 0;
}
