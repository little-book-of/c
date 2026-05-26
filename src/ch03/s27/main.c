#include <stdio.h>

void show(const int *ptr) {
    // *ptr = 10; // ❌ not allowed
    printf("Value: %d\n", *ptr);
}

int main(void) {
    int num = 5;
    const int *p = &num;
    int *const q = &num;

    printf("num = %d\n", num);

    // *p = 10; // ❌ cannot modify value through const pointer
    *q = 15;   // ✅ data modifiable through q
    printf("num after q change = %d\n", num);

    show(&num); // function accepts const pointer
    return 0;
}
