#include <stdio.h>

int main(void) {
    float c;
    printf("Celsius: ");
    scanf("%f", &c);
    float f = c * 9.0f/5.0f + 32.0f;
    printf("Fahrenheit: %.2f\n", f);
    return 0;
}
