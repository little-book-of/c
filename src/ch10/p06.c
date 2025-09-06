#include <stdio.h>

int main(void) {
    // text
    FILE *tx = fopen("ints.txt", "w");
    if (!tx) { perror("ints.txt"); return 1; }
    for (int i = 1; i <= 5; i++) fprintf(tx, "%d\n", i);
    fclose(tx);

    // binary
    FILE *bn = fopen("ints.bin", "wb");
    if (!bn) { perror("ints.bin"); return 1; }
    int a[5]; for (int i = 0; i < 5; i++) a[i] = i + 1;
    size_t n = fwrite(a, sizeof(int), 5, bn);
    if (n != 5) perror("fwrite");
    fclose(bn);
    return 0;
}
