#include <stdio.h>

int main(void) {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("copy.txt", "w");

    if (!in || !out) {
        perror("File error");
        return 1;
    }

    char buf[256];
    while (fgets(buf, sizeof(buf), in))
        fputs(buf, out);

    fclose(in);
    fclose(out);
    printf("Copied successfully.\n");
    return 0;
}
