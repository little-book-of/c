#include <stdio.h>
#include <stdlib.h>

typedef struct { int *data; size_t size, cap; } Dyn;

void init(Dyn *d) { d->data = NULL; d->size = d->cap = 0; }
int push_back(Dyn *d, int v) {
    if (d->size == d->cap) {
        size_t nc = d->cap ? d->cap * 2 : 1;
        int *nd = realloc(d->data, nc * sizeof *nd);
        if (!nd) return 0;
        d->data = nd; d->cap = nc;
    }
    d->data[d->size++] = v; return 1;
}
int pop_back(Dyn *d, int *out) {
    if (d->size == 0) return 0;
    *out = d->data[--d->size];
    return 1;
}
void destroy(Dyn *d) { free(d->data); d->data = NULL; d->size = d->cap = 0; }

int main(void) {
    Dyn d; init(&d);
    for (int i = 1; i <= 5; i++) push_back(&d, i);
    int x;
    while (pop_back(&d, &x)) printf("popped %d, size=%zu\n", x, d.size);
    destroy(&d);
    return 0;
}
