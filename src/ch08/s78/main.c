#include <assert.h>
#include <stdio.h>

int main(void) {
    int x = 5;
    assert(x == 10);  // fails
    printf("Done\n");
}
