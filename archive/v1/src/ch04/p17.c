#include <stdio.h>

int main(void) {
    int rows, cols;
    scanf("%d %d", &rows, &cols);
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) putchar('*');
        putchar('\n');
    }
    return 0;
}
