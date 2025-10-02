#include <stdio.h>

int main(void) {
    int years;
    printf("Age in years: ");
    scanf("%d", &years);
    long long days = (long long)years * 365;
    long long seconds = days * 24LL * 60LL * 60LL;
    printf("Approx seconds lived: %lld\n", seconds);
    return 0;
}
