#include <stdio.h>
#include <string.h>

typedef struct { char name[50]; char phone[20]; int age; } Contact;

#define MAXC 10

void add_contact(Contact a[], int *n, const char *name, const char *phone, int age) {
    if (*n >= MAXC) return;
    snprintf(a[*n].name,  sizeof(a[*n].name),  "%s", name);
    snprintf(a[*n].phone, sizeof(a[*n].phone), "%s", phone);
    a[*n].age = age;
    (*n)++;
}

void print_contacts(const Contact a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s %s %d\n", a[i].name, a[i].phone, a[i].age);
}

int main(void) {
    Contact book[MAXC]; int n = 0;
    add_contact(book, &n, "Alice", "123-4567", 20);
    add_contact(book, &n, "Bob",   "555-9876", 25);
    print_contacts(book, n);
    return 0;
}
