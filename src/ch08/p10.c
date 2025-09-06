#include <stdio.h>

enum TrafficLight { RED=1, YELLOW=2, GREEN=3 };

int main(void) {
    enum TrafficLight t = GREEN;
    if (t == RED) puts("Stop");
    else if (t == YELLOW) puts("Wait");
    else puts("Go");
    return 0;
}
