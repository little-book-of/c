#include <stdio.h>

int main(void) {
    FILE *fp = fopen("example.txt", "w");
    if (!fp) {
        perror("Failed to open file");
        return 1;
    }

    fprintf(fp, "Hello, file world!\n");
    fprintf(fp, "C makes you closer to the machine.\n");
    fclose(fp);

    fp = fopen("example.txt", "r");
    if (!fp) {
        perror("Failed to reopen file");
        return 1;
    }

    char line[100];
    printf("--- File Content ---\n");
    while (fgets(line, sizeof(line), fp))
        printf("%s", line);

    fclose(fp);
    return 0;
}
