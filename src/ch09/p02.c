#include <stdio.h>
#include <stdlib.h>

/* BAD: returning address of local (dangling) — shown but unused */
int *bad(void) {
    int x = 7;
    return &x;                  // ❌ don't use
}

/* GOOD: caller owns heap memory */
int *good(void) {
    int *p = malloc(sizeof *p);
    if (p) *p = 7;
    return p;
}

int main(void) {
    int *pb = bad();
    printf("dangling pointer value=%p (do not dereference)\n", (void*)pb);

    int *pg = good();
    if (pg) { printf("*pg=%d\n", *pg); free(pg); }
    return 0;
}
