#include <stdio.h>
#include <string.h>

union Value {
    int i;
    float f;
    char str[20];
};

int main(void) {
    union Value v;

    v.i = 42;
    printf("As int: %d\n", v.i);

    v.f = 3.14f;
    printf("As float: %.2f\n", v.f);

    strcpy(v.str, "Hello");
    printf("As string: %s\n", v.str);

    printf("Union size: %zu bytes\n", sizeof(v));
    return 0;
}
