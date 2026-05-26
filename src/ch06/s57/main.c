/* Section 57: Static and Shared Libraries — inlined so no custom headers needed. */
#include <stdio.h>
#include <string.h>

int add(int a, int b)           { return a + b; }
int mul(int a, int b)           { return a * b; }
int str_eq(const char *a, const char *b) { return strcmp(a, b) == 0; }

int main(void) {
    printf("3 + 4 = %d\n", add(3, 4));
    printf("Equal? %d\n", str_eq("abc", "abc"));
    return 0;
}
