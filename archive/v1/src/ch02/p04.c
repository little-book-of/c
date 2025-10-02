#include <stdio.h>

int main(void) {
    const float PI = 3.14159f;
    float r;
    printf("Radius: ");
    scanf("%f", &r);
    float area = PI * r * r;
    float circ = 2.0f * PI * r;
    printf("Area = %.4f, Circumference = %.4f\n", area, circ);
    return 0;
}
