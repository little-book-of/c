#include <stdio.h>

int main(void) {
    FILE *t = tmpfile();
    if (!t) { perror("tmpfile"); return 1; }
    fputs("scratch data\n", t);
    rewind(t);
    char buf[64];
    if (fgets(buf, sizeof buf, t)) printf("%s", buf);
    fclose(t); // file is removed automatically
    return 0;
}
