#include <stdio.h>
#include <stdlib.h>
int main(void){
    srand(1234);
    printf("%d %d %d\n", rand(), rand(), rand());
    srand(1234);
    printf("%d %d %d\n", rand(), rand(), rand());
    return 0;
}
