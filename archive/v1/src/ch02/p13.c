#include <stdio.h>

int main(void) {
    const float PI = 3.14159f;
    float r1, r2;
    printf("Enter r1 and r2: ");
    scanf("%f %f", &r1, &r2);
    float a1 = PI * r1 * r1, a2 = PI * r2 * r2;
    if (a1 > a2) printf("Circle 1 larger (%.2f > %.2f)\n", a1, a2);
    else if (a2 > a1) printf("Circle 2 larger (%.2f > %.2f)\n", a2, a1);
    else printf("Areas are equal (%.2f)\n", a1);
    return 0;
}
