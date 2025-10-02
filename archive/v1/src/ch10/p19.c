#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, ""); // enable locale for wide I/O
    FILE *f = fopen("wide.txt", "w, ccs=UTF-8"); // many compilers accept this; if not, simply use "w"
    if (!f) { perror("wide.txt"); return 1; }
    fwprintf(f, L"%ls %d\n", L"こんにちは", 42);
    fclose(f);

    f = fopen("wide.txt", "r");
    if (!f) { perror("wide.txt"); return 1; }
    wchar_t word[64]; int n;
    if (fwscanf(f, L"%63ls %d", word, &n) == 2)
        wprintf(L"Read: %ls %d\n", word, n);
    fclose(f);
    return 0;
}
