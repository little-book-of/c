#include <stdio.h>
#define LIMIT 100
int main(void){
    printf("LIMIT=%d\n", LIMIT);
    #undef LIMIT
    // printf("%d\n", LIMIT); // would not compile
    puts("LIMIT undefined");
    return 0;
}
