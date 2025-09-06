#include <stdio.h>

typedef struct { char name[50]; int age; double gpa; } Student;
typedef Student* StudentPtr;

int main(void) {
    Student s = {"Bob", 21, 3.50};
    StudentPtr sp = &s;
    printf("%s %d %.2f\n", sp->name, sp->age, sp->gpa);
    return 0;
}
