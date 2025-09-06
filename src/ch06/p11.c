#include <stdio.h>

int main(void) {
    char word[] = "dog";
    word[0] = 'f';
    printf("%s\n", word);
    return 0;
}
