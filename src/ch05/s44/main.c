#include <stdio.h>
#include <ctype.h>

int main(void) {
    int ch, words = 0, in_word = 0;

    while ((ch = getchar()) != EOF) {
        if (isspace(ch))
            in_word = 0;
        else if (!in_word) {
            in_word = 1;
            words++;
        }
    }

    printf("Word count: %d\n", words);
    return 0;
}
