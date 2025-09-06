#include <stdio.h>

int value = 100;  // global

void show_local(void) {
    int value = 50;  // shadows global
    printf("local=%d\n", value);
}

int main(void) {
    show_local();
    printf("global=%d\n", value);
    return 0;
}
