#include <stdio.h>

typedef struct { int id; double score; } Rec;

int main(void) {
    Rec v[3] = { {1, 88.5}, {2, 91.0}, {3, 76.25} };
    FILE *f = fopen("scores.bin", "wb");
    if (!f) { perror("scores.bin"); return 1; }
    size_t n = fwrite(v, sizeof(Rec), 3, f);
    if (n != 3) perror("fwrite");
    fclose(f);
    return 0;
}
