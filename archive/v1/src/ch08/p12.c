#include <stdio.h>

enum Weekday { MON=1, TUE, WED, THU, FRI, SAT, SUN };

int main(void) {
    for (enum Weekday d = MON; d <= SUN; d++)
        printf("%d\n", d);
    return 0;
}
