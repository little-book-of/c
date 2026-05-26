#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char *path = getenv("PATH");
    if (!path) path = "(none)";
    printf("Current PATH:\n%s\n", path);
    setenv("PATH", "/usr/local/bin:/usr/bin", 1);
    printf("\nUpdated PATH:\n%s\n", getenv("PATH"));
}
