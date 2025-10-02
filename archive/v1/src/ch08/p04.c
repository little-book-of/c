#include <stdio.h>

struct Student { char name[50]; int age; double gpa; };

int main(void) {
    struct Student s;
    scanf("%49s %d %lf", s.name, &s.age, &s.gpa);
    printf("%s %d %.2f\n", s.name, s.age, s.gpa);
    return 0;
}
