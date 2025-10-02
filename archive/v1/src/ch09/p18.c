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
    d->data[d->size++] = v;
    return 1;
}

void destroy(Dyn *d) { free(d->data); d->data = NULL; d->size = d->cap = 0; }

int main(void) {
    Dyn d; init(&d);
    for (int i = 1; i <= 10; i++) push_back(&d, i);
    for (size_t i = 0; i < d.size; i++) printf("%d ", d.data[i]);
    printf("\n");
    destroy(&d);
    return 0;
}
