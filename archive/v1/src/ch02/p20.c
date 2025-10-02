#include <stdio.h>

int main(void) {
    const float PI = 3.14159f;

    int age;
    float height;
    char initial;
    char name[50];

    printf("Age: ");
    scanf("%d", &age);

    printf("Height (m): ");
    scanf("%f", &height);

    printf("Initial: ");
    scanf(" %c", &initial);

    printf("Name: ");
    scanf("%49s", name);

    printf("\n--- Mini Profile ---\n");
    printf("Name   : %s\n", name);
    printf("Initial: %c\n", initial);
    printf("Age    : %d\n", age);
    printf("Height : %.2f m\n", height);
    printf("(Pi const for fun) PI = %.5f\n", PI);
    return 0;
}
