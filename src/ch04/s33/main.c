#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
} Person;

typedef Person* PersonPtr;
typedef void (*Printer)(const Person*);

void print_person(const Person *p) {
    printf("%s (%d years old)\n", p->name, p->age);
}

int main(void) {
    Person p = {"Alice", 25};
    PersonPtr ptr = &p;
    Printer print = print_person;

    print(ptr);
    return 0;
}
