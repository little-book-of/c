#include <stdio.h>
#include <string.h>

int main(void) {
    char line[256];
    if (!fgets(line, sizeof(line), stdin)) return 0;

    char longest[256] = "";
    char *tok = strtok(line, " \t\r\n");
    while (tok) {
        if (strlen(tok) > strlen(longest)) {
            strncpy(longest, tok, sizeof(longest) - 1);
            longest[sizeof(longest) - 1] = '\0';
        }
        tok = strtok(NULL, " \t\r\n");
    }
    printf("%s\n", longest);
    return 0;
}
