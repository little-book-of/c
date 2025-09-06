#include <stdio.h>

int main(void) {
#if __STDC_VERSION__ >= 202000L
    constexpr int MIN_PER_HOUR = 60;
    constexpr int HOURS_PER_DAY = 24;
    constexpr int DAYS_PER_WEEK = 7;
    constexpr int MINUTES_IN_WEEK = MIN_PER_HOUR * HOURS_PER_DAY * DAYS_PER_WEEK;
#else
    /* Fallback for older compilers */
    const int MIN_PER_HOUR = 60, HOURS_PER_DAY = 24, DAYS_PER_WEEK = 7;
    const int MINUTES_IN_WEEK = MIN_PER_HOUR * HOURS_PER_DAY * DAYS_PER_WEEK;
#endif
    printf("Minutes in a week: %d\n", MINUTES_IN_WEEK);
    return 0;
}
