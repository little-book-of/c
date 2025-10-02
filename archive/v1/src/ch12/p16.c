#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_range(int min,int max){
    return min + rand() % (max - min + 1); // simple version
}

int main(void){
    srand((unsigned)time(NULL));
    for(int i=0;i<10;i++) printf("%d ", rand_range(1,6));
    puts("");
    return 0;
}
