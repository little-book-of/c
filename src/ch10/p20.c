#include <stdio.h>

int main(void) {
    FILE *f = fopen("does_not_exist.txt", "r");
    if (f == nullptr) {             // C23 null pointer constant
        perror("open failed");
        return 1;
    }
    fclose(f);
    return 0;
}
