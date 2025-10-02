#include <stdio.h>
#include <stdlib.h>

typedef struct { double *data; size_t size, cap; } DynD;

void init(DynD *d){ d->data=NULL; d->size=d->cap=0; }
int push(DynD *d, double v){
    if (d->size == d->cap) {
        size_t nc = d->cap ? d->cap * 2 : 1;
        double *nd = realloc(d->data, nc * sizeof *nd);
        if (!nd) return 0;
        d->data = nd; d->cap = nc;
    }
    d->data[d->size++] = v; return 1;
}
void destroy(DynD *d){ free(d->data); d->data=NULL; d->size=d->cap=0; }

int main(void){
    DynD d; init(&d);
    for (int i = 0; i < 10; i++) push(&d, i + 0.5);
    for (size_t i = 0; i < d.size; i++) printf("%.2f ", d.data[i]);
    printf("\n");
    destroy(&d);
    return 0;
}
