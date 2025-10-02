#include <stdio.h>

int main(void) {
    FILE *f = fopen("numbers.txt", "r");
    if (!f) { perror("numbers.txt"); return 1; }
    long long sum = 0; int x;
    while (fscanf(f, "%d", &x) == 1) sum += x;
    if (ferror(f)) perror("read");
    if (fclose(f) == EOF) perror("close");
    printf("%lld\n", sum);
    return 0;
}
