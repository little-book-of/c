#include <stdio.h>

int main(void) {
    char c;
    scanf(" %c", &c);
    int vowel = (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
                 c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
    if (vowel) puts("vowel");
    else if ((c>='A'&&c<='Z') || (c>='a'&&c<='z')) puts("consonant");
    else puts("not a letter");
    return 0;
}
