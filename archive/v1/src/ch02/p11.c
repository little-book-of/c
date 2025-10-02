#include <stdio.h>

int main(void) {
    int days;
    printf("Days: ");
    scanf("%d", &days);
    int hours = days * 24;
    int minutes = hours * 60;
    printf("%d days = %d hours = %d minutes\n", days, hours, minutes);
    return 0;
}
