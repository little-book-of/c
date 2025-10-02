#include <stdio.h>

int main(void) {
    char name[50];
    printf("Enter your name: ");
    scanf("%49s", name);
    printf("Hello, %s! Nice to meet you.\n", name);
    return 0;
}
