#include <stdio.h>

/* prototypes */
int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);

int main(void) {
    int a, b; scanf("%d %d", &a, &b);
    printf("add=%d sub=%d mul=%d\n", add(a,b), sub(a,b), mul(a,b));
    return 0;
}

/* definitions after main */
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }
int mul(int a, int b) { return a * b; }
