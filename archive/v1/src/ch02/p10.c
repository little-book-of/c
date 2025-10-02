#include <stdio.h>

int main(void) {
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);
    int sum = a + b + c;
    float avg = sum / 3.0f;
    printf("Sum = %d, Average = %.2f\n", sum, avg);
    return 0;
}
