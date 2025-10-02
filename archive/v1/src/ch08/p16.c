#include <stdio.h>

typedef struct {
    char name[50];
    char phone[20];
    int age;
} Contact;

int main(void) {
    Contact c[3] = {
        {"Alice","123-4567",20},
        {"Bob","555-9876",25},
        {"Cara","777-0000",30}
    };
    for (int i = 0; i < 3; i++)
        printf("%s %s %d\n", c[i].name, c[i].phone, c[i].age);
    return 0;
}
