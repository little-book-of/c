#include <stdio.h>

int main(void) {
    int length, width;
    printf("Length and width: ");
    scanf("%d %d", &length, &width);
    int area = length * width;
    int peri = 2 * (length + width);
    printf("Area = %d, Perimeter = %d\n", area, peri);
    return 0;
}
