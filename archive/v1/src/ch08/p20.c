#include <stdio.h>
#include <string.h>

typedef struct { char name[50]; char phone[20]; int age; } Contact;

#define MAXC 100

void save_contacts(const char *path, const Contact a[], int n) {
    FILE *f = fopen(path, "w");
    if (!f) return;
    for (int i = 0; i < n; i++)
        fprintf(f, "%s;%s;%d\n", a[i].name, a[i].phone, a[i].age);
    fclose(f);
}

int load_contacts(const char *path, Contact a[], int maxn) {
    FILE *f = fopen(path, "r");
    if (!f) return 0;
    int n = 0;
    while (n < maxn &&
           fscanf(f, " %49[^;];%19[^;];%d", a[n].name, a[n].phone, &a[n].age) == 3) {
        n++;
        int ch = fgetc(f); (void)ch; // consume newline if present
    }
    fclose(f);
    return n;
}

int main(void) {
    Contact out[3] = {
        {"Alice","123-4567",20},
        {"Bob","555-9876",25},
        {"Cara","777-0000",30}
    };
    save_contacts("contacts.txt", out, 3);

    Contact in[MAXC];
    int n = load_contacts("contacts.txt", in, MAXC);
    for (int i = 0; i < n; i++)
        printf("%s %s %d\n", in[i].name, in[i].phone, in[i].age);
    return 0;
}
