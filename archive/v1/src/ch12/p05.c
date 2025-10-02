#include <stdio.h>
int main(void){
    char w[128]; int n=1;
    while (scanf("%127s", w)==1) printf("%d: %s\n", n++, w);
    return 0;
}
