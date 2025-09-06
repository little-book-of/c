#include <stdio.h>
#include "shapes.h"

int main(void) {
    double w = 3, h = 4, r = 2.5;
    printf("rect: area=%.2f perim=%.2f\n", area_rectangle(w,h), perimeter_rectangle(w,h));
    printf("circle: area=%.2f\n", area_circle(r));
    return 0;
}
