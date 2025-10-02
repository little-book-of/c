#include <stdio.h>

typedef struct { int id; double score; } Rec;

int main(void) {
    FILE *f = fopen("scores.bin", "rb");
    if (!f) { perror("scores.bin"); return 1; }
    Rec v[3]; size_t n = fread(v, sizeof(Rec), 3, f);
    if (n != 3 && ferror(f)) perror("fread");
    for (size_t i = 0; i < n; i++)
        printf("id=%d score=%.2f\n", v[i].id, v[i].score);
    fclose(f);
    return 0;
}
