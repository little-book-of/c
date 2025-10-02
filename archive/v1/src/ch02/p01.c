#include <stdio.h>

int main(void) {
    char name[50];
    int age;
    char fav;

    printf("Enter your name: ");
    scanf("%49s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    printf("Enter your favorite character: ");
    scanf(" %c", &fav);

    printf("\nHello %s! You are %d years old and your favorite character is %c.\n",
           name, age, fav);
    return 0;
}
