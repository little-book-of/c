#include <stdio.h>

int add(int a,int b){return a+b;}
int sub(int a,int b){return a-b;}
int mul(int a,int b){return a*b;}
int div_int(int a,int b){return a/b;} // assume b!=0 for this exercise

int main(void) {
    int (*ops[4])(int,int) = {add, sub, mul, div_int};
    int a = 12, b = 3;
    const char *names[4] = {"add","sub","mul","div"};
    for (int i = 0; i < 4; i++) {
        printf("%s=%d\n", names[i], ops[i](a,b));
    }
    return 0;
}
