#include <stdio.h>
#include <string.h>

typedef struct { char name[50]; char phone[20]; int age; } Contact;

#define MAXC 10

int find_contact(const Contact a[], int n, const char *name) {
    for (int i = 0; i < n; i++)
        if (strcmp(a[i].name, name) == 0) return i;
    return -1;
}

int main(void) {
    Contact book[MAXC] = {
        {"Alice","123-4567",20},
        {"Bob","555-9876",25},
        {"Cara","777-0000",30}
    };
    int n = 3;
    char key[50]; scanf("%49s", key);
    int idx = find_contact(book, n, key);
    if (idx >= 0) printf("%s %s %d\n", book[idx].name, book[idx].phone, book[idx].age);
    else puts("Not found");
    return 0;
}
