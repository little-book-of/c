#include <stdio.h>

#define PI 3.14159           // preprocessor constant
const int DAYS_IN_WEEK = 7;  // read-only variable

enum Direction { NORTH, EAST, SOUTH, WEST }; // enumerated constants

int main(void) {
    printf("Pi: %.2f\n", PI);
    printf("Days in a week: %d\n", DAYS_IN_WEEK);
    printf("Direction EAST has value: %d\n", EAST);
    return 0;
}
