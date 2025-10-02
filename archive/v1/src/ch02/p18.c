#include <stdio.h>
#include <string.h>

int main(void) {
    char name[50];
    printf("Enter your name: ");
    scanf("%49s", name);

    size_t w = strlen(name) + 4; // "* " + name + " *"
    for (size_t i = 0; i < w; ++i) putchar('*');
    putchar('\n');
    printf("* %s *\n", name);
    for (size_t i = 0; i < w; ++i) putchar('*');
    putchar('\n');
    return 0;
}
