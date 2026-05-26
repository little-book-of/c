/* Section 58: Compiler Flags — shows an uninitialized variable warning.
   Compile with: cc -Wall -Wextra -Wuninitialized main.c */
#include <stdio.h>

int main(void) {
    int x;          /* uninitialized: -Wall will warn about this */
    x = 42;         /* assignment silences the warning in practice */
    printf("%d\n", x);
    return 0;
}
