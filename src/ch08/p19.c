#include <stdio.h>
#include <string.h>

typedef struct { char name[50]; char phone[20]; int age; } Contact;

#define MAXC 10

int find_contact(const Contact a[], int n, const char *name) {
    for (int i = 0; i < n; i++)
        if (strcmp(a[i].name, name) == 0) return i;
    return -1;
}

void delete_contact(Contact a[], int *n, const char *name) {
    int idx = find_contact(a, *n, name);
    if (idx < 0) return;
    for (int i = idx; i < *n - 1; i++) a[i] = a[i+1];
    (*n)--;
}

void print_contacts(const Contact a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%s %s %d\n", a[i].name, a[i].phone, a[i].age);
}

int main(void) {
    Contact book[MAXC] = {
        {"Alice","123-4567",20},
        {"Bob","555-9876",25},
        {"Cara","777-0000",30}
    };
    int n = 3;
    delete_contact(book, &n, "Bob");
    print_contacts(book, n);
    return 0;
}
