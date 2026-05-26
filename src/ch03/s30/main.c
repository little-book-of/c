#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int age;
    float gpa;
} Student;

Student *create_student(const char *name, int age, float gpa) {
    Student *s = malloc(sizeof(Student));
    if (!s) {
        printf("Memory allocation failed for Student.\n");
        exit(1);
    }

    s->name = malloc(strlen(name) + 1);
    if (!s->name) {
        printf("Memory allocation failed for name.\n");
        free(s);
        exit(1);
    }

    strcpy(s->name, name);
    s->age = age;
    s->gpa = gpa;

    return s;
}

void print_student(const Student *s) {
    printf("Name: %-10s | Age: %d | GPA: %.2f\n", s->name, s->age, s->gpa);
}

void free_student(Student *s) {
    free(s->name);
    free(s);
}

int main(void) {
    printf("=== Manual Memory Management Demo ===\n");

    // Create three students dynamically
    Student *a = create_student("Alice", 20, 3.8f);
    Student *b = create_student("Bob", 22, 3.4f);
    Student *c = create_student("Carol", 19, 3.9f);

    // Print their details
    print_student(a);
    print_student(b);
    print_student(c);

    // Modify dynamically allocated memory
    strcpy(b->name, "Bobby");
    b->gpa = 3.6f;
    printf("\nAfter update:\n");
    print_student(b);

    // Free memory
    free_student(a);
    free_student(b);
    free_student(c);

    printf("\nAll memory released.\n");
    return 0;
}
