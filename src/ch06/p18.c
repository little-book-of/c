#include <stdio.h>
#include <string.h>

int main(void) {
    char line[256];
    if (!fgets(line, sizeof(line), stdin)) return 0;

    int count = 0;
    char *tok = strtok(line, " \t\r\n");
    while (tok) { count++; tok = strtok(NULL, " \t\r\n"); }
    printf("%d\n", count);
    return 0;
}
