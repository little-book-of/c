#include <stdio.h>
#include <unistd.h>

int main(void) {
    for (int i = 5; i > 0; i--) {
        printf("%d...\n", i);
        sleep(1);
    }
    printf("Time's up!\n");
}
