/* Section 87: Using C with Other Languages (FFI) — self-contained demo. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* In a real FFI scenario, greet() would be exported to Python/Go/etc.
   Here it is inlined to keep the file standalone. */
const char *greet(const char *name) {
    static char buf[64];
    snprintf(buf, sizeof(buf), "Hello, %s!", name);
    return buf;
}

int main(void) {
    printf("%s\n", greet("World"));
    printf("%s\n", greet("C FFI"));
    return 0;
}
