#include <stdio.h>

int main(void) {
#if __STDC_VERSION__ >= 202311L
    printf("C23 or newer\n");
#elif __STDC_VERSION__ >= 201710L
    printf("C17\n");
#elif __STDC_VERSION__ >= 201112L
    printf("C11\n");
#elif __STDC_VERSION__ >= 199901L
    printf("C99\n");
#else
    printf("C90 or earlier\n");
#endif
}
