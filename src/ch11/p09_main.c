#include <stdio.h>
#include "p09_shapes.h"
int main(void){
    printf("area=%d\n", area_rect(3,4));
    Color c=RED;
    printf("color=%d\n", c);
    Point p={5,7};
    printf("point=(%d,%d)\n", p.x, p.y);
    return 0;
}
