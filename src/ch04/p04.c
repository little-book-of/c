#include <stdio.h>

int main(void) {
    float c;
    scanf("%f", &c);
    if (c < 10.0f) printf("Cold\n");
    else if (c <= 25.0f) printf("Warm\n");
    else printf("Hot\n");
    return 0;
}
