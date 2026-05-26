/* Section 99: Packaging, Versioning, and Documentation — standalone demo. */
#include <stdio.h>

#define MYPROJECT_VERSION_MAJOR 1
#define MYPROJECT_VERSION_MINOR 0
#define MYPROJECT_VERSION_PATCH 0

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main(void) {
    printf("myproject v%d.%d.%d\n",
           MYPROJECT_VERSION_MAJOR,
           MYPROJECT_VERSION_MINOR,
           MYPROJECT_VERSION_PATCH);
    printf("add(10, 3) = %d\n", add(10, 3));
    printf("sub(10, 3) = %d\n", sub(10, 3));
    return 0;
}
