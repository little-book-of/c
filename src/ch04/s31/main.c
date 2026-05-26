#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Person {
    char name[50];
    int age;
    float height;
    struct Date birthdate;
};

void print_person(const struct Person *p) {
    printf("%s, %d years old, born on %02d/%02d/%04d, height %.2fm\n",
           p->name, p->age,
           p->birthdate.day, p->birthdate.month, p->birthdate.year,
           p->height);
}

int main(void) {
    struct Person person = {"Alice", 25, 1.68f, {1, 2, 1999}};

    print_person(&person);

    person.age++;
    person.birthdate.year++;
    printf("After update:\n");
    print_person(&person);

    return 0;
}
