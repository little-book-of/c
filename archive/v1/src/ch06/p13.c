#include <stdio.h>
#include <string.h>

int main(void) {
    char s[200];
    if (!fgets(s, sizeof(s), stdin)) return 0;
    size_t len = strcspn(s, "\n"); // length without trailing newline
    printf("%zu\n", len);
    return 0;
}
