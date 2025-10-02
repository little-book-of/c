#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);
    int both_pos = (a > 0 && b > 0);
    int any_pos  = (a > 0 || b > 0);
    int not_both = !both_pos;
    printf("both_pos=%d any_pos=%d not_both=%d\n", both_pos, any_pos, not_both);
    return 0;
}
