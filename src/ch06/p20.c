#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LEN   32

int main(void) {
    char line[512];
    if (!fgets(line, sizeof(line), stdin)) return 0;

    char words[MAX_WORDS][MAX_LEN];
    int counts[MAX_WORDS] = {0};
    int total = 0;

    for (char *tok = strtok(line, " \t\r\n"); tok; tok = strtok(NULL, " \t\r\n")) {
        // truncate token if too long for storage
        char key[MAX_LEN];
        strncpy(key, tok, MAX_LEN - 1);
        key[MAX_LEN - 1] = '\0';

        int idx = -1;
        for (int i = 0; i < total; i++) {
            if (strcmp(words[i], key) == 0) { idx = i; break; }
        }
        if (idx >= 0) {
            counts[idx]++;
        } else if (total < MAX_WORDS) {
            strcpy(words[total], key);
            counts[total] = 1;
            total++;
        }
    }

    for (int i = 0; i < total; i++) {
        printf("%s %d\n", words[i], counts[i]);
    }
    return 0;
}
