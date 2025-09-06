#include <stdio.h>

void line(int n) { for (int i = 0; i < n; i++) putchar('-'); putchar('\n'); }

int main(void) {
    line(5); line(10); line(3);
    return 0;
}
