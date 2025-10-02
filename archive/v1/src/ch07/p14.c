#include <stdio.h>
#include <stdlib.h>

/* BAD: returns address of local variable (dangling) */
int *bad_ptr(void) {
    int x = 10;
    return &x; /* DO NOT USE */
}

/* GOOD: allocate on heap, caller must free */
int *good_ptr(void) {
    int *p = malloc(sizeof(*p));
    if (p) *p = 10;
    return p;
}

int main(void) {
    int *pb = bad_ptr();
    /* Printing the pointer value itself is defined, but dereferencing *pb is UB.
       printf("*pb=%d\n", *pb); // ❌ don't do this
    */
    printf("dangling address=%p (do not dereference)\n", (void*)pb);

    int *pg = good_ptr();
    if (pg) {
        printf("*pg=%d\n", *pg);
        free(pg);
        pg = NULL;
    }
    return 0;
}
