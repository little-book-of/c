#include <stdio.h>

int main(void) {
    int numbers[] = {10, 20, 30, 40, 50};
    size_t count = sizeof(numbers) / sizeof(numbers[0]);

    FILE *fp = fopen("numbers.bin", "wb");
    if (!fp) {
        perror("Failed to open file");
        return 1;
    }

    fwrite(numbers, sizeof(int), count, fp);
    fclose(fp);

    printf("Wrote %zu integers to numbers.bin\n", count);
    return 0;
}
