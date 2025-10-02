#include <stdio.h>

int main(void) {
    int x = 10;
    {
        int y = 20;
        printf("inside: x=%d y=%d\n", x, y);
    }
    /* Uncommenting the next line causes a compile error: y not visible here */
    /* printf("outside: y=%d\n", y); */
    return 0;
}
