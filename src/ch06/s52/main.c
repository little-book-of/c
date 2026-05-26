#include <stdio.h>

#define PI 3.14159
#define CIRCLE_AREA(r) (PI * (r) * (r))
#define SQUARE(x) ((x) * (x))

int main(void) {
    printf("PI = %.2f\n", PI);
    printf("Area of circle (r=2): %.2f\n", CIRCLE_AREA(2));
    printf("Square of 5: %d\n", SQUARE(5));
    return 0;
}
