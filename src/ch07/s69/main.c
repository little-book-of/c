#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void) {
    FILE *f = fopen("data.txt", "r");
    if (!f) {
        fprintf(stderr, "Error: %s\n", strerror(errno));
        return EXIT_FAILURE;
    }

    char buf[64];
    while (fgets(buf, sizeof(buf), f))
        printf("%s", buf);

    fclose(f);
    return EXIT_SUCCESS;
}
