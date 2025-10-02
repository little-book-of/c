#include <stdio.h>

int main(void) {
    int grade;
    printf("Grade (0-100): ");
    scanf("%d", &grade);
    printf("%s\n", grade >= 50 ? "Pass" : "Fail");
    return 0;
}
