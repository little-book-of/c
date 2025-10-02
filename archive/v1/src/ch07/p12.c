#include <stdio.h>

int add(int a,int b){return a+b;}
int sub(int a,int b){return a-b;}
int mul(int a,int b){return a*b;}
int div_int(int a,int b){return a/b;}

int main(void) {
    int a, b; char op;
    if (scanf("%d %d %c", &a, &b, &op) != 3) return 0;

    int (*f)(int,int) = NULL;
    switch (op) {
        case '+': f = add; break;
        case '-': f = sub; break;
        case '*': f = mul; break;
        case '/': f = div_int; break;
        default: puts("unknown op"); return 0;
    }
    if (op == '/' && b == 0) { puts("divide by zero"); return 0; }
    printf("%d\n", f(a,b));
    return 0;
}
