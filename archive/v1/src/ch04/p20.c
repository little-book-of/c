#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    if (n < 2) { puts("Not prime"); return 0; }

    int is_prime = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) { is_prime = 0; break; }
    }
    puts(is_prime ? "Prime" : "Not prime");
    return 0;
}
