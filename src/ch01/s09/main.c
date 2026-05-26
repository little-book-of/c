/* Self-contained example of the minimal project structure from section 9.
   Normally greet() lives in src/greet.c and its declaration in include/greet.h,
   but here everything is inlined so the file compiles on its own. */
#include <stdio.h>

void greet(const char *name) {
    printf("Hello, %s!\n", name);
}

int main(void) {
    greet("C Learner");
    return 0;
}
