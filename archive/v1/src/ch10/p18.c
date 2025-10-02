#include <stdio.h>

int main(void) {
    if (!freopen("out.txt", "w", stdout)) { perror("freopen"); return 1; }
    printf("redirected output\n");
    // stdout now writes to out.txt
    return 0;
}
