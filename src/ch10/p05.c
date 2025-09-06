#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *in = fopen("input.txt", "r");
    if (!in) { perror("input.txt"); return 1; }
    FILE *out = fopen("long.txt", "w");
    if (!out) { perror("long.txt"); fclose(in); return 1; }

    char line[4096];
    while (fgets(line, sizeof line, in)) {
        if (strlen(line) > 10) {
            if (fputs(line, out) == EOF) { perror("write"); break; }
        }
    }
    if (ferror(in)) perror("read");

    fclose(in); fclose(out);
    return 0;
}
