#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    enum { N = 1000 };
    void *blocks[N] = {0};
    srand((unsigned)time(NULL));

    // allocate random sizes
    for (int i = 0; i < N; i++) {
        size_t sz = (size_t)(rand() % 4096 + 1);
        blocks[i] = malloc(sz);
        if (!blocks[i]) { puts("allocation failed"); break; }
    }

    // free every third block
    for (int i = 0; i < N; i += 3) {
        free(blocks[i]);
        blocks[i] = NULL;
    }

    // attempt more allocations
    for (int i = 0; i < N; i++) {
        if (!blocks[i]) {
            blocks[i] = malloc(2048);
            if (!blocks[i]) puts("later allocation failed (possible fragmentation)");
        }
    }

    // cleanup
    for (int i = 0; i < N; i++) free(blocks[i]);
    puts("done");
    return 0;
}
