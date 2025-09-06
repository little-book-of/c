#include <stdio.h>

enum Weekday { MON=1, TUE, WED, THU, FRI, SAT, SUN };

int main(void) {
    enum Weekday d = WED;
    printf("%d\n", d);
    return 0;
}
