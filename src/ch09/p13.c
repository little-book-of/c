#include <stdio.h>
#include <stddef.h> // NULL

int main(void) {
    int *a = NULL;
    int *b = nullptr;   // C23
    printf("a==NULL? %s\n", (a == NULL) ? "yes" : "no");
    printf("b==nullptr? %s\n", (b == nullptr) ? "yes" : "no");
    printf("b==0? %s\n", (b == 0) ? "yes" : "no"); // null equals integer constant 0
    return 0;
}
