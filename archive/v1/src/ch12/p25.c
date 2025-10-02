#include <stdio.h>
#include <ctype.h>
#include <string.h>

int is_palindrome(const char *s){
    size_t i=0, j=strlen(s);
    if (j==0) return 1;
    j--;
    while (i<j){
        while (i<j && !isalnum((unsigned char)s[i])) i++;
        while (i<j && !isalnum((unsigned char)s[j])) j--;
        if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) return 0;
        i++; j--;
    }
    return 1;
}

int main(void){
    const char *a="Radar";
    const char *b="level";
    const char *c="not this";
    printf("%s -> %d\n", a, is_palindrome(a));
    printf("%s -> %d\n", b, is_palindrome(b));
    printf("%s -> %d\n", c, is_palindrome(c));
    return 0;
}
