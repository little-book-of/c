#include <stdio.h>

typedef enum { V_INT, V_FLOAT } Tag;

typedef struct {
    Tag tag;
    union { int i; float f; } val;
} Variant;

void print_variant(Variant v) {
    if (v.tag == V_INT) printf("int=%d\n", v.val.i);
    else printf("float=%.2f\n", v.val.f);
}

int main(void) {
    Variant a = { V_INT,   .val.i = 42 };
    Variant b = { V_FLOAT, .val.f = 3.5f };
    print_variant(a);
    print_variant(b);
    return 0;
}
