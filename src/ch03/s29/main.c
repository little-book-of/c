#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
} Person;

void print_person(const char *label, Person p) {
    printf("%s: name=%s age=%d\n", label, p.name, p.age);
}

int main(void) {
    Person p1;
    p1.name = malloc(20);
    strcpy(p1.name, "Alice");
    p1.age = 25;

    // Shallow copy
    Person p2 = p1;
    print_person("Before", p1);
    p2.name[0] = 'M'; // modifies same memory
    print_person("After shallow copy", p1);

    // Deep copy
    Person p3;
    p3.name = malloc(strlen(p1.name) + 1);
    strcpy(p3.name, p1.name);
    p3.age = p1.age;

    p3.name[0] = 'C'; // independent copy
    print_person("After deep copy", p1);
    print_person("Deep copy result", p3);

    free(p1.name);
    free(p3.name); // ✅ safe
    return 0;
}
