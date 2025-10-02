#include <stdio.h>

int main(void) {
    FILE *f = fopen("hello.txt", "w");
    if (!f) { perror("hello.txt"); return 1; }
    fputs("Hello, File!\n", f);
    if (fclose(f) == EOF) { perror("close"); return 1; }
    return 0;
}
