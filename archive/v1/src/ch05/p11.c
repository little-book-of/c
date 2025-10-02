#include <stdio.h>

int counter = 0;  // global

void tick(void) { counter++; }

int main(void) {
    for (int i = 0; i < 5; i++) tick();
    printf("%d\n", counter);
    return 0;
}
