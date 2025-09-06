#include <stdio.h>
#define SQUARE(x) ((x)*(x))
inline int square(int x){ return x*x; }

int main(void){
    int i=2;
    printf("%d %d\n", SQUARE(3), square(3));
    printf("%d %d\n", SQUARE(3+1), square(3+1));
    i=2; printf("macro:%d\n", SQUARE(i++)); // multiple eval
    i=2; printf("inline:%d\n", square(i++)); // single eval
    return 0;
}
