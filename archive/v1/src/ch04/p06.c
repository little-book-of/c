#include <stdio.h>

int main(void) {
    int d;
    scanf("%d", &d);
    switch (d) {
        case 0: puts("zero"); break;
        case 1: puts("one"); break;
        case 2: puts("two"); break;
        case 3: puts("three"); break;
        case 4: puts("four"); break;
        case 5: puts("five"); break;
        case 6: puts("six"); break;
        case 7: puts("seven"); break;
        case 8: puts("eight"); break;
        case 9: puts("nine"); break;
        default: puts("not a digit");
    }
    return 0;
}
