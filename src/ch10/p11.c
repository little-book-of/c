#include <stdio.h>
#include <stdlib.h>

int main(void) {
    FILE *in = fopen("source.txt", "rb");
    if (!in) { perror("source.txt"); return 1; }
    FILE *out = fopen("dest.txt", "wb");
    if (!out) { perror("dest.txt"); fclose(in); return 1; }

    unsigned char buf[8192];
    size_t n;
    while ((n = fread(buf, 1, sizeof buf, in)) > 0) {
        size_t w = fwrite(buf, 1, n, out);
        if (w != n) { perror("write"); fclose(in); fclose(out); return 1; }
    }
    if (ferror(in)) perror("read");

    if (fclose(in) == EOF) perror("close in");
    if (fclose(out) == EOF) perror("close out");
    return 0;
}
