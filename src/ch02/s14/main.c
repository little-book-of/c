#include <stdio.h>

int main(void) {
    int temperature = 30;

    if (temperature > 35) {
        printf("It's too hot!\n");
    } else if (temperature > 25) {
        printf("It's warm.\n");
    } else {
        printf("It's cool.\n");
    }

    return 0;
}
