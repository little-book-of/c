#include <stdio.h>

int main(void) {
    FILE *f = fopen("numbers.txt", "w");
    if (!f) { perror("numbers.txt"); return 1; }
    for (int i = 1; i <= 10; i++) fprintf(f, "%d\n", i);
    if (fclose(f) == EOF) perror("close");
    return 0;
}
