#include <stdio.h>

int main(void) {
    FILE *in = fopen("source.txt", "r");
    if (!in) { perror("source.txt"); return 1; }
    FILE *out = fopen("dest.txt", "w");
    if (!out) { perror("dest.txt"); fclose(in); return 1; }

    char buf[4096];
    while (fgets(buf, sizeof buf, in)) {
        if (fputs(buf, out) == EOF) { perror("write"); break; }
    }
    if (ferror(in)) perror("read");

    if (fclose(in) == EOF) perror("close in");
    if (fclose(out) == EOF) perror("close out");
    return 0;
}
