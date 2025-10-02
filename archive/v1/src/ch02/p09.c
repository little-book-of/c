#include <stdio.h>

int main(void) {
    float h, w;
    printf("Height (m) and Weight (kg): ");
    scanf("%f %f", &h, &w);
    float bmi = w / (h * h);
    printf("BMI = %.2f\n", bmi);
    return 0;
}
