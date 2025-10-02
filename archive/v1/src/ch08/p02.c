#include <stdio.h>

struct Student {
    char name[50];
    int age;
    double gpa;
};

int main(void) {
    struct Student s = {"Alice", 20, 3.80};
    printf("%s %d %.2f\n", s.name, s.age, s.gpa);
    return 0;
}
