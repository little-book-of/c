#include <stdio.h>

int main(void) {
    // text
    FILE *tx = fopen("ints.txt", "r");
    if (!tx) { perror("ints.txt"); return 1; }
    int x;
    puts("from text:");
    while (fscanf(tx, "%d", &x) == 1) printf("%d ", x);
    puts("");
    fclose(tx);

    // binary
    FILE *bn = fopen("ints.bin", "rb");
    if (!bn) { perror("ints.bin"); return 1; }
    int arr[5]; size_t n = fread(arr, sizeof(int), 5, bn);
    if (n != 5 && ferror(bn)) perror("fread");
    puts("from binary:");
    for (size_t i = 0; i < n; i++) printf("%d ", arr[i]);
    puts("");
    fclose(bn);
    return 0;
}
