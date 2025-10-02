#include <stdio.h>
int main(void){
    for(int i=1;i<=5;i++) printf("%d\n", i);       // stdout
    fprintf(stderr, "this is an error message\n"); // stderr
    return 0;
}
