#include <stdio.h>
#include <string.h>

int main(void) {
    char msg[] = "C language";
    char *ptr = msg; // pointer to the first character

    printf("String: %s\n", msg);
    printf("Length: %zu\n", strlen(msg));

    printf("\nCharacters one by one:\n");
    for (int i = 0; msg[i] != '\0'; i++) {
        printf("msg[%d] = %c (address: %p)\n", i, msg[i], (void *)&msg[i]);
    }

    printf("\nAccess via pointer arithmetic:\n");
    for (int i = 0; *(ptr + i) != '\0'; i++) {
        printf("*(ptr + %d) = %c\n", i, *(ptr + i));
    }

    // Modify string safely
    msg[0] = 'C';
    msg[1] = '+';
    printf("\nModified string: %s\n", msg);

    return 0;
}
