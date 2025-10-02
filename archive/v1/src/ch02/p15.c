#include <stdio.h>

int main(void) {
    int year = 2025;
    float height = 1.72f;
    char grade = 'A';
    char name[] = "Alice";

    printf("Name: %s\nYear: %d\nHeight: %.2f m\nGrade: %c\n",
           name, year, height, grade);
    return 0;
}
